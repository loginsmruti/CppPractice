#include <iostream>
#include <ctime>
 
using namespace std; 

// Basic state from which all other states are derived
class state {
    private:
        int this_state;
    public:
        state(int new_state) : this_state(new_state) { };
        virtual state * change_state(int choice) = 0;
        void wait_a_second();
};

// On hook state, also the start and end state
class state_1 : public state {
    public:
        state_1() : state(1) { };
        state * change_state(int choice);
};

// Ringing state
class state_2 : public state {
    private:
        int ring_count;
    public:
        state_2() : state(2), ring_count(0) { };
        state * change_state(int choice);
};

// Connected state
class state_3 : public state {
   private:
        int count;
    public:
        state_3() : state(3), count(0) { };
        state * change_state(int choice);
};

// Off hook state
class state_4 : public state {
   private:
        int count;
    public:
        state_4() : state(4), count(0) { };
        state * change_state(int choice);
};

// Dialling state
class state_5 : public state {
    private:
        int ring_count;
    public:
        state_5() : state(5), ring_count(0) { };
        state * change_state(int choice);
};

// Remote ringing state
class state_6 : public state {
    private:
        int count;
    public:
        state_6() : state(6), count(0) { };
        state * change_state(int choice);
};

// Remote busy state
class state_7 : public state {
    public:
        state_7() : state(7) { };
        state * change_state(int choice);
};

// Disconnected state
class state_8 : public state {
    public:
        state_8() : state(8) { };
        state * change_state(int choice);
};

// A cross-platform wait a second or two method
void state::wait_a_second() {
    time_t time_current = time(NULL);
    while ( time(NULL) <= time_current+1 );
}

// On hook state. Transition to ringing or off-hook
state * state_1::change_state(int choice) {
    cout << "on hook" << endl;
    if ( choice == 0 )
        reinterpret_cast<state_2 *>(this)->state_2::state_2(); 
    else
        reinterpret_cast<state_4 *>(this)->state_4::state_4(); 
    wait_a_second();
    return this; 
};

// Ringing state. Transition to connected or on-hook
state * state_2::change_state(int choice) {
    if ( ring_count == 0 ) cout << "ringing" << endl;
    if ( choice == 1 ) {
        reinterpret_cast<state_3 *>(this)->state_3::state_3();
        wait_a_second();
        return this; 
    }
    ring_count++;
    if ( ring_count == 5 ) {
        reinterpret_cast<state_1 *>(this)->state_1::state_1();
    }
    wait_a_second();
    return this; 
};

// Connected state. Transition to on-hook or disconnected
state * state_3::change_state(int choice) {
    if ( count == 0 ) cout << "connected" << endl; 
    count++;
    if ( choice == 1 ) {
        if ( count == 5 ) {
            reinterpret_cast<state_1 *>(this)->state_1::state_1();
        }
        wait_a_second();
        return this; 
    }
    if ( count == 5 ) {
        reinterpret_cast<state_8 *>(this)->state_8::state_8();
    }
    wait_a_second();
    return this; 
};

// Off hook state. Transition to on-hook or dialling
state * state_4::change_state(int choice) {
    cout << "off hook" << endl; 
    if ( choice == 1 ) {
        reinterpret_cast<state_1 *>(this)->state_1::state_1();
        wait_a_second();
        return this; 
    }
    reinterpret_cast<state_5 *>(this)->state_5::state_5();
    wait_a_second();
    return this; 
};

// Dialing state. Transition to remote ringing, remote busy or on-hook
state * state_5::change_state(int choice) {
    cout << "dialling" << endl; 
    if ( choice == 0 ) {
        reinterpret_cast<state_6 *>(this)->state_6::state_6(); 
        wait_a_second();
        return this; 
    }
    if ( choice == 1 )
        reinterpret_cast<state_7 *>(this)->state_7::state_7();
    else
        reinterpret_cast<state_1 *>(this)->state_1::state_1();
    wait_a_second();
    return this; 
};

// Remote ringing state. Transition to connected or on-hook
state * state_6::change_state(int choice) {
    if ( count == 0 ) cout << "remote ringing" << endl; 
    if ( choice == 1 ) {
        reinterpret_cast<state_3 *>(this)->state_3::state_3();
        wait_a_second();
        return this; 
    }
    count++;
    if ( count == 5 ) {
        reinterpret_cast<state_1 *>(this)->state_1::state_1();
    }
    wait_a_second();
    return this; 
};

// Remote busy state. Transition to on-hook
state * state_7::change_state(int choice) {
    cout << "remote busy" << endl; 
    reinterpret_cast<state_1 *>(this)->state_1::state_1(); 
    wait_a_second();
    return this; 
};

// Disconnected state. Transition to on-hook
state * state_8::change_state(int choice) {
    cout << "disconnected" << endl; 
    reinterpret_cast<state_1 *>(this)->state_1::state_1(); 
    wait_a_second();
    return this; 
};

// The finite state machine
class finite_state_machine {
    private:
        state * current_state;
    public:
        finite_state_machine() : current_state(new state_1()) { srand(static_cast<unsigned int>(time(NULL))); };
        void next_state(int choice) { current_state = current_state->change_state(choice); };
        void simulate_telephone() {
            while ( true ) {
                int state_shift = rand()%3;
                next_state(state_shift);
            }
        };
};

// main routine
int main () {
    finite_state_machine fsm;
    fsm.simulate_telephone();
}
