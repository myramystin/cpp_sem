#include "car.h"
#include "truck.h"
#include "vechicle.h"
#include "park.h"

#include "factory.h"
#include "inspection.h"

#include <iostream>
#include <memory>

int main() {


    // TTruck t("m", 1.0);
    // t.do_sth();

    // TDumpTruck dt("m1", 1.0);
    // dt.do_sth();

    // // std::vector<TTruck> trucks;
    // // trucks.push_back(TDumpTruck); <- not works

    // TTruck* truck_ptr = &dt;

    // std::vector<TTruck*> trucks;
    // trucks.push_back(&dt)

    // truck_ptr->do_sth();

    /* 
        "sedan" -> car
        "jeep" -> car
        "truck" -> truck
        "duptruck" -> dt

        std::unordered_map<string, IVechicle*> 

        std::sthared_ptr<...> = &t;
        auto = make_shared<...>

    */

    /*
        class Foo {
            void a() {
                b();
            }
            virtual void b();
        }

    class Bar : Foo{
        void b() override;
    }
    
    Bar bar;
    Foo* f = &bar;
    f->a();

    f->this->a()
    this->b
    
    */

    TVehicleFactory::initialize();
    auto sedan = TVehicleFactory::create("sedan");
    if (sedan) {
        std::cout << sedan->getInfo() << "\n";
        sedan->start();
    }

    auto truck = TVehicleFactory::create("truck");
    if (truck) {
        std::cout << truck->getInfo()  << "\n";
        truck->start();
    }

    auto dumptruck = TVehicleFactory::create("dumptruck");
    if (dumptruck) {
        std::cout << dumptruck->getInfo() << "\n";
        dumptruck->start();
    }

    TVehicleFactory::registerType("park", [&]()->std::shared_ptr<IVehicle>  {
        auto group = std::make_shared<TVehicleGroup>("dasha's group of cars");
        group->addVehicle(dumptruck);
        return group;
    });

    auto park = TVehicleFactory::create("park");
    if (park) {
        std::cout << park->getInfo() << "\n";
        park->start();
    }

    // park->addVehicle(dumptruck);

    std::cout << std::string(60, '=') << "\n";

    std::shared_ptr<TVehicleGroup> park2 = std::make_shared<TVehicleGroup>("other cars group");
    
    park2->addVehicle(std::make_shared<TCar>("Mercedes", 4));
    park2->addVehicle(std::make_shared<TCar>("Audi", 5));
    park2->addVehicle(std::make_shared<TTruck>("MAN", 18.0));
    
    std::cout << "\n" << park2->getInfo() << "\n";
    
    // Работаем с группой как с одним объектом
    park2->start();
    park2->stop();


    std::cout << std::string(60, '=') << "\n";

    TInspectionVisitor insp;
    park2->accept(insp);

    insp.printReport();

    return 0;
}