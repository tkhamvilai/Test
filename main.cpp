#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void print_AERSP()
{
  while ( 1 )
  {
    std::cout << "AERSP" << std::endl;
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
  }
}

void print_424()
{
  while ( 1 )
  {
    std::cout << "424" << std::endl;
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
  }
}

void print( std::string s )
{
  while ( 1 )
  {
    std::cout << s << std::endl;
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
  }
}

int main() 
{
  std::thread t1( print_AERSP );
  std::thread t2( print_424 );

  // alternative
  //std::thread t1( print, "AERSP" );
  //std::thread t2( print, "424" );

  t1.join();
  t2.join();
  return 0;
}
