#include "front.hpp"
#include <iostream>
#include <list>
using namespace std;

Ingredient::Ingredient(){
    this->category = unspecified;
    this->quantity = 1;
}

Ingredient::Ingredient(int quantity, Food_class category, string expiry date){
    this.
}



// replace this 
void Ingredient::saveToJsonFile(const std ::string& fileIngredients){
        rapidjson:: Document doc; 
        doc.SetObject(); 
        doc.AddMember("expirary_dates", rapidjson::Value(expiry_date.c_str(), doc.GetAllocator()), doc.GetAllocator());
        doc.AddMember("Quantity", quantity, doc.GetAllocator());
        std::string prioritystatus;
        switch (prioritystatus) {
            case red:
                prioritystatus = "red";
                break;
            case orange:
                prioritystatus = "orange";
                break;
            case green:
                prioritystatus = "green";
                break;
        }
        rapidjson::Value enumpriority(rapidjson::kStringType);
        enumpriority.SetString(prioritystatus.c_str(), static_cast<rapidjson::SizeType>(prioritystatus.length()), doc.GetAllocator());
        doc.AddMember("Priority", enumpriority, doc.GetAllocator());

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        std::string jsonStr = buffer.GetString();
