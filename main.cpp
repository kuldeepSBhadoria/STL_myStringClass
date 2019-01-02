#include <iostream>
//#include <string.h>

using namespace std;

class Complex
{
private:
  char *a;
  int length;

public:
  void setData (char *b)
  {
      int l = my_strlen(b);
      a = (char *)malloc(sizeof(char)*l);
      for(int i=0;i<l;i++)
      {
          a[i] = b[i];
      }
      length = l;
  }
  void displayData ()
  {
      cout<<endl;
      for(int i=0;i<length;i++)
         cout<< a[i];
  }
  void my_strncpy( char * ptr_dest, char * ptr_src, int n )
  {
        for( int i=0; i < n; i++ )
          ptr_dest[i] = ptr_src[i];
  }
  int my_strlen( char * ptr )
  {    
    int len = 0;
    char * p = ptr;
    while( *p != '\0' ) 
    {
      len++;
      p++;
    }
  return len;
}

  Complex operator=(const Complex& s1)
{
  Complex res;
    cout << "  myString::operator=\n";
    length = s1.length;  
    a = new char[length];        
    my_strncpy( a, s1.a, length );

  return res;  
}
  
  friend Complex operator+(const Complex& s1, const Complex& s2);
  friend bool operator==(const Complex& s1, const Complex& s2);
};
bool operator==(const Complex& s1, const Complex& s2)
  {
    bool res;
    if(s1.length != s2.length)
        return false;
    else
    {
        for(int i=0;i<s1.length;i++)
        {
            if(s1.a[i] != s2.a[i])
                return false;
            res = true;
        }
    }

    return res;
  }
Complex operator+(const Complex& s1, const Complex& s2)
  {
    Complex res;
    res.length = s1.length + s2.length;
    res.a = new char[ res.length ];
    res.my_strncpy( res.a, s1.a, s1.length );
    res.my_strncpy( res.a + s1.length, s2.a, s2.length );
    return res;
  }
int main ()
{
  Complex c1, c3, c2,c4;
  c1.setData("hello");
  c2.setData("kuldeep");
  c1.displayData ();
  c3 = c1+c2;
  c3.displayData ();
  c4 = c1;
  c4.displayData();
  if(c1==c2)
      printf(" \n true");
  else
      cout<<"\nfalse"<<endl;
    if(c1==c4)
      printf(" \n true");
  else
      cout<<"\nfalse"<<endl;
  
  return 0;
}

