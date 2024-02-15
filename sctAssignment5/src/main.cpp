#include "../include/Menu.hpp"
#include "../include/json.hpp"
#include <fstream>

using json = nlohmann::json;

void loadMenuFromJSON(std::shared_ptr<menu::Menu> menu, const std::string& filename);

int main() {

    MenuInterface denemeInterface;

    std::shared_ptr<menu::Menu> allMenu = std::make_shared<menu::Menu>();

    std::shared_ptr<menu::Menu> Usermenu = std::make_shared<menu::Menu>();

    loadMenuFromJSON(allMenu, "../menu.json");

    denemeInterface.setMenu(allMenu);

    denemeInterface.Welcome();

    denemeInterface.Registration(Usermenu);

    int selection = 0;

    do{
        int selection = denemeInterface.UserMenu();
        switch(selection){
            case -1:
                std::cout << "You have entered wrong selection 5 times. Exiting from the system." << std::endl;
                return 0;

            case 0:
                std::cout << "Invalid selection. Please try again." << std::endl;
                break;

            case 1:
                Usermenu->resetMenu();
                denemeInterface.Registration(Usermenu);
                break;
            case 2:
                denemeInterface.Goodbye();
                break;

            case 3:
                denemeInterface.Selection();
                std::cout << "Would you like to go back to main menu ? (Y/N)" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    continue;
                }
                else{
                    denemeInterface.Goodbye();
                    return 0;
                }
                break;

            case 4:
                std::cout << "If you want to give parameters for suggestions, please enter them." << std::endl;
                std::cout << "Salty: ";
                float salty;
                std::cin >> salty;
                std::cout << "Bitter: ";
                float bitter;
                std::cin >> bitter;
                std::cout << "Sour: ";
                float sour;
                std::cin >> sour;
                std::cout << "Sweet: ";
                float sweet;
                std::cin >> sweet;
                std::cout << "Savory: ";
                float savory;
                std::cin >> savory;
                
                denemeInterface.Suggesstion(salty, bitter, sour, sweet, savory);
                
                break;

            default:
                std::cerr << "System Failure !" << std::endl;
                return -1;
        }
    }while(true);

    return 0;
}

void loadMenuFromJSON(std::shared_ptr<menu::Menu> menu, const std::string& filename){

    std::ifstream f(filename);
    json menu_data = json::parse(f);

    for (const std::string category : {"starters", "salads", "main_courses", "drinks", "appetizers", "desserts"}) {
        for (const auto& item : menu_data[category]) {
            json taste_balance = item["taste_balance"];
            int sweet = taste_balance["sweet"];
            int sour = taste_balance["sour"];
            int bitter = taste_balance["bitter"];
            int salty = taste_balance["salty"];
            int savory = taste_balance["savory"];
            if (category == "starters"){
                std::shared_ptr<menu::Starter> menuItem = std::make_shared<menu::Starter>(item["name"], item["price"], sweet, sour, bitter, salty, savory);
                menu->addStarter(menuItem);
            }
            else if (category == "salads"){
                std::shared_ptr<menu::Salad> menuItem = std::make_shared<menu::Salad>(item["name"], item["price"], sweet, sour, bitter, salty, savory);
                menu->addSalad(menuItem);
            
            }
            else if(category == "main_courses"){
                std::shared_ptr<menu::MainCourse> menuItem = std::make_shared<menu::MainCourse>(item["name"], item["price"], sweet, sour, bitter, salty, savory);   
                menu->addMainCourse(menuItem);
            
            }
            else if(category == "drinks"){
                std::shared_ptr<menu::Drink> menuItem = std::make_shared<menu::Drink>(item["name"], item["price"], sweet, sour, bitter, salty, savory);
                menu->addDrink(menuItem);
            
            }
            else if(category == "appetizers"){
                std::shared_ptr<menu::Appetizer> menuItem = std::make_shared<menu::Appetizer>(item["name"], item["price"], sweet, sour, bitter, salty, savory);
                menu->addAppetizer(menuItem);
            
            }
            else if(category == "desserts"){
                std::shared_ptr<menu::Dessert> menuItem = std::make_shared<menu::Dessert>(item["name"], item["price"], sweet, sour, bitter, salty, savory);
                menu->addDessert(menuItem);           
            }
        }
    }
}