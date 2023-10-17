#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

int main(int, char**){
  httplib::Client client("https://api.github.com");

  client.set_default_headers({{ "User-Agent", "Ohio-Northern-Demo-Cpp" }});

  auto response = client.Get("/octocat");
  std::cout << response->body << std::endl;

  return 0;
}
