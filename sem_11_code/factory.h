#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "car.h"
#include "truck.h"
#include "dumptruck.h"

#include <iostream>


class TVehicleFactory {
private:
    using TCreatorFunc = std::function<std::shared_ptr<IVehicle>()>;
    
    // std::function<ReturnType(ArgType1, ArgType2)>;

    // Статическая карта создателей
    static std::unordered_map<std::string, TCreatorFunc>& getRegistry() {
        static std::unordered_map<std::string, TCreatorFunc> registry;
        return registry;
    }
    
public:
    // Статическая регистрация типа
    static void registerType(const std::string& type, TCreatorFunc creator) {
        
        getRegistry()[type] = creator;
        std::cout << "Registered '" << type << "\n";
    
    }
    
    // Статическое создание транспорта
    static std::shared_ptr<IVehicle> create(const std::string& type) {
        auto& registry = getRegistry();
        auto it = registry.find(type);
        
        if (it != registry.end()) {
            return it->second();
        }
        
        std::cout << "Unknown type " << type << "\n";
        return nullptr;
    }
    
    // Получить список всех типов
    static std::vector<std::string> getAvailableTypes() {
        std::vector<std::string> types;
        for (const auto& pair : getRegistry()) {
            types.push_back(pair.first);
        }
        return types;
    }
    
    // Статическая инициализация стандартных типов
    static void initialize() {
        std::cout << "\nInit transport...\n";
        
        registerType("sedan", []() -> std::shared_ptr<IVehicle> {
            return std::make_shared<TCar>("Toyota Camry", 4);
        });
        
        registerType("suv", []() -> std::shared_ptr<IVehicle> {
            return std::make_shared<TCar>("Land Cruiser", 5);
        });
        
        registerType("truck", []() -> std::shared_ptr<IVehicle> {
            return std::make_shared<TTruck>("Volvo FH", 20.0);
        });
        
        registerType("dumptruck", []() -> std::shared_ptr<IVehicle> {
            return std::make_shared<TDumpTruck>("Volvo DumpTruck", 40.0);
        });
    }
};
