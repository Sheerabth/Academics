#ifndef WS4_2_H_INCLUDED
#define WS4_2_H_INCLUDED

class Set
{
  int* set;
  int size;
  int top;
  public:
  Set(int);
  void add();
  void remove();
  void display();
  Set operator | (Set);
  Set operator & (Set);
};

#endif // WS4_2_H_INCLUDED
