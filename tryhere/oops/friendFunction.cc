#include<iostream>

class Storage; // forward declaration for class Storage

class Display
{
  private:
    bool m_displayIntFirst;

  public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(Storage &storage); // forward declaration above needed for this declaration line
};

class Storage // full definition of Storage class
{
  private:
    int m_nValue;
    double m_dValue;
  public:
    Storage(int nValue, double dValue)
    {
      m_nValue = nValue;
      m_dValue = dValue;
    }

    // Make the Display class a friend of Storage (requires seeing the full declaration of class Display, as above)
    friend void Display::displayItem(Storage& storage);
};

// Now we can define Display::displayItem, which needs to have seen the full declaration of class Storage
void Display::displayItem(Storage &storage)
{
  if (m_displayIntFirst)
    std::cout << storage.m_nValue << " " << storage.m_dValue << '\n';
  else // display double first
    std::cout << storage.m_dValue << " " << storage.m_nValue << '\n';
}

int main()
{
  Storage storage(5, 6.7);
  Display display(false);

  display.displayItem(storage);

  return 0;
}
