
#include "front.hpp"
#include <iostream>
#include <list>
using namespace std;


void Ingredient::saveToJsonFile(const std::string& fileINgredient) {
    rapidjson::Document doc;
    doc.SetObject();

    doc.AddMember("expiry_date", rapidjson::Value(get_expiry_date().c_str(), doc.GetAllocator()).Move(), doc.GetAllocator());
    doc.AddMember("Quantity", get_Quant(), doc.GetAllocator());

    std::string prioritystatus;
    switch (get_priority()) {
        case Priority::red:
            prioritystatus = "red";
            break;
        case Priority::orange:
            prioritystatus = "orange";
            break;
        case Priority::green:
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

    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << jsonStr;
        outputFile.close();
        std::cout << "Status saved to " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


void Fridge :: saveListToJson(const std::string& filename) {
        rapidjson::Document doc;
        doc.SetArray();

        for (const Ingredient& ingredient : ingredient_list) {
            rapidjson::Value obj(rapidjson::kObjectType);
            obj.AddMember("expiry_date", rapidjson::Value(ingredient.get_expiry_date().c_str(), doc.GetAllocator()).Move(), doc.GetAllocator());
            obj.AddMember("Quantity", ingredient.get_Quantity(), doc.GetAllocator());

            std::string prioritystatus;
            switch (ingredient.get_priority()) {
                case Priority::red:
                    prioritystatus = "red";
                    break;
                case Priority::orange:
                    prioritystatus = "orange";
                    break;
                case Priority::green:
                    prioritystatus = "green";
                    break;
            }

            rapidjson::Value enumpriority(rapidjson::kStringType);
            enumpriority.SetString(prioritystatus.c_str(), static_cast<rapidjson::SizeType>(prioritystatus.length()), doc.GetAllocator());
            obj.AddMember("Priority", enumpriority, doc.GetAllocator());

            doc.PushBack(obj, doc.GetAllocator());
        }

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        std::string jsonStr = buffer.GetString();

        std::ofstream outputFile(filename);
        if (outputFile.is_open()) {
            outputFile << jsonStr;
            outputFile.close();
            std::cout << "Fridge content saved to " << filename << " successfully." << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

