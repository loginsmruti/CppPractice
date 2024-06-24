#include <iostream>
#include <memory>

class Partner {
    
    std::weak_ptr<Partner> partner;
    public:
    Partner() = default;
    Partner(const Partner& Partner) = delete;
    
    friend void parter(std::shared_ptr<Partner>& partner, std::shared_ptr<Partner>& partner_2);

};

void parter(std::shared_ptr<Partner>& P1, std::shared_ptr<Partner>& P2) {
    P1->partner = P2;
    P2->partner = P1;
}

int main () {
auto P1  = std::make_shared<Partner>();
auto P2 = std::make_shared<Partner>();
    
    parter(P1, P2);

    return 0;
}