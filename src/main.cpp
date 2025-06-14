#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

int main() {
    std::string city;
    std::cout << "Enter the city: ";
    std::getline(std::cin, city);

    std::string apiKey = "9ff77f5f2cf22ff088bd38a088fdcba2"; 
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    cpr::Response r = cpr::Get(cpr::Url{url});
    if (r.status_code != 200) {
        std::cerr << "Request error: " << r.status_code << "\n";
        return 1;
    }

    auto json = nlohmann::json::parse(r.text);
    std::cout << "Temperature: " << json["main"]["temp"] << " °C\n";
    std::cout << "Description: " << json["weather"][0]["description"] << "\n";
    return 0;
}