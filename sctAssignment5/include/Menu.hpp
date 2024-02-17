#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace menu{

    class MenuItem{
        public:
            MenuItem();
            std::string getName() const;
            float getPrice() const;
            float getSweetness() const;
            float getSourness() const;
            float getSaltiness() const;
            float getBitterness() const;
            float getSavoriness() const;

            void setName(std::string name);
            void setPrice(float price);
            void setSweetness(float sweetness);
            void setSourness(float sourness);
            void setSaltiness(float saltiness);
            void setBitterness(float bitterness);
            void setSavoriness(float savoriness);

        private:
            std::string name;
            float price;
            float sweetness;
            float sourness;
            float saltiness;
            float bitterness;
            float savoriness;
    };


    class Starter : public MenuItem {
        public:
            Starter();
            Starter(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            bool getIsHot() const;
            void setIsHot(bool isHot);
        private:
            bool isHot = false; // true if hot, false if cold
    };

    class Salad : public MenuItem {
        public:
            Salad();
            Salad(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            std::vector<std::string> getToppings() const;
            void setToppings(const std::vector<std::string>& toppings);
            float getPricePerTopping() const;
        private:
            std::vector<std::string> toppings; // 2.5$ per topping
            float pricePerTopping;
    };

    class MainCourse : public MenuItem {
        public:
            MainCourse();
            MainCourse(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
    };

    class Drink : public MenuItem {
        public:
            Drink();
            Drink(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            bool getIsCarbonated() const;
            void setIsCarbonated(bool isCarbonated);
            bool getIsExtraShot() const;
            void setIsExtraShot(bool isExtraShot);
            float getPriceForExtraShot() const;
            float getPriceForCarbonated() const;
        private:
            bool isCarbonated = false; // 0.5$ extra if carbonated
            bool isExtraShot = false; // 2.5$ extra if extra shot
            const float priceForExtraShot{0.5};
            const float priceForCarbonated{2.5};
    };

    class Appetizer : public MenuItem {
        public:
            Appetizer();
            Appetizer(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            bool getIsAfterMainCourse() const;
            void setIsAfterMainCourse(bool isAfterMainCourse);
        private:
            bool isAfterMainCourse = false; // true if after main course, false if before
    };

    class Dessert : public MenuItem {
        public:
            Dessert();
            Dessert(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            bool getIsExtraChocolate() const;
            void setIsExtraChocolate(bool isExtraChocolate);
            float getPriceForExtraChocolate() const;
        private:
            bool isExtraChocolate = false; // 1.5$ extra if extra chocolate
            float priceForExtraChocolate{1.5};
    };

    

    class Menu {
        public:
            void removeItem(std::shared_ptr<MenuItem> item);
            void resetMenu();
            float getOverallSweetness() const;
            float getOverallSourness() const;
            float getOverallSaltiness() const;
            float getOverallBitterness() const;
            float getOverallSavoriness() const;
            float getTotalCost() const;

            void addStarter(std::shared_ptr<Starter> starter);
            void addSalad(std::shared_ptr<Salad> salad);
            void addMainCourse(std::shared_ptr<MainCourse> mainCourse);
            void addDrink(std::shared_ptr<Drink> drink);
            void addAppetizer(std::shared_ptr<Appetizer> appetizer);
            void addDessert(std::shared_ptr<Dessert> dessert);

            std::vector<std::shared_ptr<menu::Starter>> getStarters();
            std::vector<std::shared_ptr<menu::Salad>> getSalads();
            std::vector<std::shared_ptr<menu::MainCourse>> getMainCourses();
            std::vector<std::shared_ptr<menu::Drink>> getDrinks();
            std::vector<std::shared_ptr<menu::Appetizer>> getAppetizers();
            std::vector<std::shared_ptr<menu::Dessert>> getDesserts();

        private:
            std::vector<std::shared_ptr<Starter>> starters;
            std::vector<std::shared_ptr<Salad>> salads;
            std::vector<std::shared_ptr<MainCourse>> mainCourses;
            std::vector<std::shared_ptr<Drink>> drinks;
            std::vector<std::shared_ptr<Appetizer>> appetizers;
            std::vector<std::shared_ptr<Dessert>> desserts;
            size_t totalItems = 0;
            float overallSweetness;
            float overallSourness;
            float overallSaltiness;
            float overallBitterness;
            float overallSavoriness;
            float totalCost;
    };

    class User{
        public:
            void setFirstName(std::string name);
            void setLastName(std::string name);
            void setTitle(std::string title);
            void setChosenMenu(std::shared_ptr<Menu> menu);
            std::string getFirstName() const;
            std::string getLastName() const;
            std::string getTitle() const;
            std::shared_ptr<Menu> getChosenMenu() const;
        private:
            std::string firstName;
            std::string lastName;
            std::string title;
            std::shared_ptr<Menu> chosenMenu;
    };
    
}
    class MenuInterface{
        public:
            void Welcome();
            void setMenu(std::shared_ptr<menu::Menu>);
            void Registration(std::shared_ptr<menu::Menu>);
            int UserMenu();
            void Selection();
            void StarterMenu();
            void SaladMenu();
            void MainCourseMenu();
            void DrinkMenu();
            void AppetizerMenu();
            void DessertMenu();
            void Summary();
            void Suggesstion();
            void Suggesstion(float sweetness, float sourness, float saltiness, float bitterness, float savoriness);
            void Goodbye();

        private:
            std::shared_ptr<menu::User> user = nullptr;
            std::shared_ptr <menu::Menu> allMenu = nullptr;
            size_t repeatation = 0;
    };
    
#endif