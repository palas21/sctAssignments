#include "Menu.hpp"

namespace menu{

    std::string MenuItem::getName() const {
        return this->name;
    }

    float MenuItem::getPrice() const {
        return this->price;
    }

    float MenuItem::getSweetness() const {
        return this->sweetness;
    }

    float MenuItem::getSourness() const {
        return this->sourness;
    }

    float MenuItem::getSaltiness() const {
        return this->saltiness;
    }

    float MenuItem::getBitterness() const {
        return this->bitterness;
    }

    float MenuItem::getSavoriness() const {
        return this->savoriness;
    }

    void MenuItem::setName(std::string name) {
        this->name = name;
    }

    void MenuItem::setPrice(float price) {
        this->price = price;
    }

    void MenuItem::setSweetness(float sweetness) {
        this->sweetness = sweetness;
    }

    void MenuItem::setSourness(float sourness) {
        this->sourness = sourness;
    }

    void MenuItem::setSaltiness(float saltiness) {
        this->saltiness = saltiness;
    }

    void MenuItem::setBitterness(float bitterness) {
        this->bitterness = bitterness;
    }

    void MenuItem::setSavoriness(float savoriness) {
        this->savoriness = savoriness;
    }

    Starter::Starter(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    bool Starter::getIsHot() const {
        return this->isHot;
    }

    void Starter::setIsHot(bool isHot) {
        this->isHot = isHot;
    }

    Salad::Salad(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    std::vector<std::string> Salad::getToppings() const {
        return this->toppings;
    }

    void Salad::setToppings(const std::vector<std::string>& toppings) {
        this->toppings = toppings;
    }

    float Salad::getPricePerTopping() const {
        return this->pricePerTopping;
    }

    MainCourse::MainCourse(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    Drink::Drink(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    bool Drink::getIsExtraShot() const {
        return this->isExtraShot;
    }

    void Drink::setIsExtraShot(bool isExtraShot) {
        this->isExtraShot = isExtraShot;
    }

    float Drink::getPriceForExtraShot() const {
        return this->priceForExtraShot;
    }

    float Drink::getPriceForCarbonated() const {
        return this->priceForCarbonated;
    }

    bool Drink::getIsCarbonated() const {
        return this->isCarbonated;
    }

    void Drink::setIsCarbonated(bool isCarbonated) {
        this->isCarbonated = isCarbonated;
    }

    Appetizer::Appetizer(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    bool Appetizer::getIsAfterMainCourse() const {
        return this->isAfterMainCourse;
    }

    void Appetizer::setIsAfterMainCourse(const bool isAfterMainCourse) {
        this->isAfterMainCourse = isAfterMainCourse;
    }

    Dessert::Dessert(std::string name, float price, float sweetness, float sourness, float saltiness, float bitterness, float savoriness) {
        this->setName(name);
        this->setPrice(price);
        this->setSweetness(sweetness);
        this->setSourness(sourness);
        this->setSaltiness(saltiness);
        this->setBitterness(bitterness);
        this->setSavoriness(savoriness);
    }

    bool Dessert::getIsExtraChocolate() const {
        return this->isExtraChocolate;
    }

    void Dessert::setIsExtraChocolate(bool isExtraChocolate) {
        this->isExtraChocolate = isExtraChocolate;
    }

    float Dessert::getPriceForExtraChocolate() const {
        return this->priceForExtraChocolate;
    }

    void Menu::resetMenu() {
        this->starters.clear();
        this->salads.clear();
        this->mainCourses.clear();
        this->drinks.clear();
        this->appetizers.clear();
        this->desserts.clear();
        this->overallBitterness = 0;
        this->overallSaltiness = 0;
        this->overallSavoriness = 0;
        this->overallSourness = 0;
        this->overallSweetness = 0;
        this->totalCost = 0;
    }

    void Menu::removeItem(std::shared_ptr<MenuItem> item) {
        
    }

    float Menu::getOverallSweetness() const {
        return this->overallSweetness;
    }

    float Menu::getOverallSourness() const {
        return this->overallSourness;
    }

    float Menu::getOverallSaltiness() const {
        return this->overallSaltiness;
    }

    float Menu::getOverallBitterness() const {
        return this->overallBitterness;
    }

    float Menu::getOverallSavoriness() const {
        return this->overallSavoriness;
    }

    float Menu::getTotalCost() const {
        return this->totalCost;
    }

    void Menu::addStarter(std::shared_ptr<Starter> starter) {
        this->totalItems++;
        this->overallBitterness = (starter->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (starter->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (starter->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (starter->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (starter->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += starter->getPrice();
        this->starters.push_back(starter);
    }

    void Menu::addSalad(std::shared_ptr<Salad> salad) {
        this->totalItems++;
        this->overallBitterness = (salad->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (salad->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (salad->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (salad->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (salad->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += salad->getPrice();
        this->totalCost += salad->getPricePerTopping() * salad->getToppings().size();
        this->salads.push_back(salad);
    }

    void Menu::addMainCourse(std::shared_ptr<MainCourse> mainCourse) {
        this->totalItems++;
        this->overallBitterness = (mainCourse->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (mainCourse->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (mainCourse->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (mainCourse->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (mainCourse->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += mainCourse->getPrice();
        this->mainCourses.push_back(mainCourse);
    }

    void Menu::addDrink(std::shared_ptr<Drink> drink) {
        this->totalItems++;
        this->overallBitterness = (drink->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (drink->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (drink->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (drink->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (drink->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += drink->getPrice();
        this->totalCost += drink->getPriceForExtraShot() * drink->getIsExtraShot();
        this->totalCost += drink->getPriceForCarbonated() * drink->getIsCarbonated();
        this->drinks.push_back(drink);
    }

    void Menu::addAppetizer(std::shared_ptr<Appetizer> appetizer) {
        this->totalItems++;
        this->overallBitterness = (appetizer->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (appetizer->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (appetizer->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (appetizer->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (appetizer->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += appetizer->getPrice();

        this->appetizers.push_back(appetizer);
    }

    void Menu::addDessert(std::shared_ptr<Dessert> dessert) {
        this->totalItems++;
        this->overallBitterness = (dessert->getBitterness() + this->overallBitterness * (this->totalItems - 1)) / this->totalItems;
        this->overallSaltiness = (dessert->getSaltiness() + this->overallSaltiness * (this->totalItems - 1)) / this->totalItems;
        this->overallSavoriness = (dessert->getSavoriness() + this->overallSavoriness * (this->totalItems - 1)) / this->totalItems;
        this->overallSourness = (dessert->getSourness() + this->overallSourness * (this->totalItems - 1)) / this->totalItems;
        this->overallSweetness = (dessert->getSweetness() + this->overallSweetness * (this->totalItems - 1)) / this->totalItems;
        this->totalCost += dessert->getPrice();
        this->totalCost += dessert->getPriceForExtraChocolate() * dessert->getIsExtraChocolate();
        this->desserts.push_back(dessert);
    }

    std::vector<std::shared_ptr<menu::Starter>> Menu::getStarters() {
        return this->starters;
    }

    std::vector<std::shared_ptr<menu::Salad>> Menu::getSalads() {
        return this->salads;
    }

    std::vector<std::shared_ptr<menu::MainCourse>> Menu::getMainCourses() {
        return this->mainCourses;
    }

    std::vector<std::shared_ptr<menu::Drink>> Menu::getDrinks() {
        return this->drinks;
    }

    std::vector<std::shared_ptr<menu::Appetizer>> Menu::getAppetizers() {
        return this->appetizers;
    }

    std::vector<std::shared_ptr<menu::Dessert>> Menu::getDesserts() {
        return this->desserts;
    }


    void User::setFirstName(std::string name) {
        this->firstName = name;
    }

    void User::setLastName(std::string name) {
        this->lastName = name;
    }

    void User::setTitle(std::string title) {
        this->title = title;
    }

    void User::setChosenMenu(std::shared_ptr<Menu> menu) {
        this->chosenMenu = menu;
    }

    std::string User::getFirstName() const {
        return this->firstName;
    }

    std::string User::getLastName() const {
        return this->lastName;
    }

    std::string User::getTitle() const {
        return this->title;
    }

    std::shared_ptr<Menu> User::getChosenMenu() const {
        return this->chosenMenu;
    }
}

    void MenuInterface::Welcome() {
        std::cout << "Welcome to the Menu Interface\nPlease enter your informations!\n";
    }

    void MenuInterface::setMenu(std::shared_ptr<menu::Menu> chosenMenu) {
        this->allMenu = chosenMenu;
    }

    void MenuInterface::Registration(std::shared_ptr<menu::Menu> chosenMenu) {
        std::cout << "Please enter your first name: ";
        std::string firstName;
        std::cin >> firstName;
        std::cout << "Please enter your last name: ";
        std::string lastName;
        std::cin >> lastName;
        std::cout << "Please enter your title: ";
        std::string title;
        std::cin >> title;

        std::shared_ptr<menu::User> user = std::make_shared<menu::User>();
        user->setFirstName(firstName);
        user->setLastName(lastName);
        user->setTitle(title);
        user->setChosenMenu(chosenMenu);
        this->user = user;
    }

    int MenuInterface::UserMenu() {
        std::cout << "Welcome " << user->getTitle() << " " << user->getLastName() << std::endl;
        std::cout << "Please select an option from the menu below." << std::endl;
        std::cout << "1 - Change user." << std::endl;
        std::cout << "2 - Exit from the system." << std::endl;
        std::cout << "3 - Choose a menu." << std::endl;
        std::cout << "4 - Suggestions." << std::endl;
        int selection = 0;
        std::cin >> selection;
        switch (selection){
            case 1:
                this->repeatation = 0;
                return 1;
            case 2:
                return 2;
            case 3:
                this->repeatation = 0;
                return 3;
            case 4:
                this->repeatation = 0;
                return 4;
            default:
                if(this->repeatation < 5){
                    this->repeatation++;
                    return 0;
                }else{
                    return -1;
                }
        }
    }

    void MenuInterface::Selection() {
        std::cout << "Please select a menu from the list below." << std::endl;
        this->StarterMenu();
        this->SaladMenu();
        this->MainCourseMenu();
        this->DrinkMenu();
        this->AppetizerMenu();
        this->DessertMenu();
        this->Summary();
    }

    void MenuInterface::StarterMenu(){
        std::cout << "Starter Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getStarters().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getStarters()[i]->getName() << " - " << this->allMenu->getStarters()[i]->getPrice() << std::endl;
        }      
        while(true){
            std::cout << "Please choose a starter from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getStarters().size()){
                std::cout << "You have chosen " << this->allMenu->getStarters()[selection-1]->getName() << std::endl;
                std::cout << "\nWould you like your starter to be hot? (Y/N): " << std::endl;
                char answer;
                std::cin >> answer;
                menu::Starter starter = *this->allMenu->getStarters()[selection-1];
                if(answer == 'Y' || answer == 'y'){
                    starter.setIsHot(true);
                }
                user->getChosenMenu()->addStarter(std::make_shared<menu::Starter>(starter));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;

            }
        }
    }

    void MenuInterface::SaladMenu() {
        std::cout << "Salad Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getSalads().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getSalads()[i]->getName() << " - " << this->allMenu->getSalads()[i]->getPrice() << std::endl;
        }
        while(true){
            std::cout << "Please choose a salad from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getSalads().size()){
                std::cout << "You have chosen " << this->allMenu->getSalads()[selection-1]->getName() << std::endl;
                std::cout << "\nWould you like to add toppings to your salad? (Y/N)" << std::endl;
                char answer;
                std::cin >> answer;
                std::vector<std::string> toppings;
                if(answer == 'Y' || answer == 'y'){
                    std::cout << "Please enter the toppings you would like to add to your salad. (Press -1 to finish)" << std::endl;
                    std::string topping;
                    while(true){
                        std::cin >> topping;
                        if(topping == "-1"){
                            break;
                        }
                        toppings.push_back(topping);
                    }
                }
                menu::Salad salad = *this->allMenu->getSalads()[selection-1];
                salad.setToppings(toppings);
                user->getChosenMenu()->addSalad(std::make_shared<menu::Salad>(salad));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;

            }
        }

    }

    void MenuInterface::MainCourseMenu() {
        std::cout << "Main Course Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getMainCourses().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getMainCourses()[i]->getName() << " - " << this->allMenu->getMainCourses()[i]->getPrice() << std::endl;
        }

        while(true){
            std::cout << "Please choose a main course from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getMainCourses().size()){
                std::cout << "You have chosen " << this->allMenu->getMainCourses()[selection-1]->getName() << std::endl;
                menu::MainCourse mainCourse = *this->allMenu->getMainCourses()[selection-1];
                user->getChosenMenu()->addMainCourse(std::make_shared<menu::MainCourse>(mainCourse));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }

    }
    
    void MenuInterface::DrinkMenu() {
        std::cout << "Drink Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getDrinks().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getDrinks()[i]->getName() << " - " << this->allMenu->getDrinks()[i]->getPrice() << std::endl;
        }

        while(true){
            std::cout << "Please choose a drink from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getDrinks().size()){
                std::cout << "You have chosen " << this->allMenu->getDrinks()[selection-1]->getName() << std::endl;
                std::cout << "\nWould you like to add extra shot to your drink ? (Y/N)" << std::endl;
                char answer;
                std::cin >> answer;
                menu::Drink drink = *this->allMenu->getDrinks()[selection-1];
                if(answer == 'Y' || answer == 'y'){
                    drink.setIsExtraShot(true);
                }
                std::cout << "\nWould you like your drink to be carbonated ? (Y/N)" << std::endl;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    drink.setIsCarbonated(true);
                }
                user->getChosenMenu()->addDrink(std::make_shared<menu::Drink>(drink));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;

            }
        }
    }

    void MenuInterface::AppetizerMenu() {
        std::cout << "Appetizer Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getAppetizers().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getAppetizers()[i]->getName() << " - " << this->allMenu->getAppetizers()[i]->getPrice() << std::endl;
        }
        while(true){
            std::cout << "Please choose an appetizer from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getAppetizers().size()){
                std::cout << "You have chosen " << this->allMenu->getAppetizers()[selection-1]->getName() << std::endl;
                menu::Appetizer appetizer = *this->allMenu->getAppetizers()[selection-1];
                std::cout << "\nWould you like your appetizer to be served after main course ? (Y/N)" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    appetizer.setIsAfterMainCourse(true);
                }
                user->getChosenMenu()->addAppetizer(std::make_shared<menu::Appetizer>(appetizer));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;

            }
        }
    }

    void MenuInterface::DessertMenu() {
        std::cout << "Dessert Menu" << std::endl;
        for(int i = 0; i < this->allMenu->getDesserts().size(); i++){
            std::cout << i+1 << " - " << this->allMenu->getDesserts()[i]->getName() << " - " << this->allMenu->getDesserts()[i]->getPrice() << std::endl;
        }
        while(true){
            std::cout << "Please choose a dessert from the list above." << std::endl;
            int selection;
            std::cin >> selection;
            if(selection > 0 && selection <= this->allMenu->getDesserts().size()){
                std::cout << "You have chosen " << this->allMenu->getDesserts()[selection-1]->getName() << std::endl;
                menu::Dessert dessert = *this->allMenu->getDesserts()[selection-1];
                std::cout << "Would you like to add extra chocolate to your dessert ? (Y/N)" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    dessert.setIsExtraChocolate(true);
                }
                user->getChosenMenu()->addDessert(std::make_shared<menu::Dessert>(dessert));
            }else if(selection == -1){
                break;
            }
            else{
                std::cout << "Invalid selection. Please try again." << std::endl;

            }
        }
    }

    void MenuInterface::Summary() {
        std::cout << "Summary" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "Starters : " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getStarters().size(); i++){
            std::cout << user->getChosenMenu()->getStarters()[i]->getName() << " - " << user->getChosenMenu()->getStarters()[i]->getPrice() << std::endl;
        }
        std::cout << "Salads : " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getSalads().size(); i++){
            std::cout << user->getChosenMenu()->getSalads()[i]->getName() << " - " << user->getChosenMenu()->getSalads()[i]->getPrice() << std::endl;
        }
        std::cout << "Appetizers (Before Main Course): " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getAppetizers().size(); i++){
            if(!user->getChosenMenu()->getAppetizers()[i]->getIsAfterMainCourse()){
                std::cout << user->getChosenMenu()->getAppetizers()[i]->getName() << " - " << user->getChosenMenu()->getAppetizers()[i]->getPrice() << std::endl;
            }
        }
        std::cout << "Main Courses : " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getMainCourses().size(); i++){
            std::cout << user->getChosenMenu()->getMainCourses()[i]->getName() << " - " << user->getChosenMenu()->getMainCourses()[i]->getPrice() << std::endl;
        }
        std::cout << "Appetizers (After Main Course): " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getAppetizers().size(); i++){
            if(user->getChosenMenu()->getAppetizers()[i]->getIsAfterMainCourse()){
                std::cout << user->getChosenMenu()->getAppetizers()[i]->getName() << " - " << user->getChosenMenu()->getAppetizers()[i]->getPrice() << std::endl;
            }
        }
        std::cout << "Drinks : " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getDrinks().size(); i++){
            std::cout << user->getChosenMenu()->getDrinks()[i]->getName() << " - " << user->getChosenMenu()->getDrinks()[i]->getPrice() << std::endl;
        }
        std::cout << "Desserts : " << std::endl;
        for(int i = 0; i < user->getChosenMenu()->getDesserts().size(); i++){
            std::cout << user->getChosenMenu()->getDesserts()[i]->getName() << " - " << user->getChosenMenu()->getDesserts()[i]->getPrice() << std::endl;
        }
        std::cout << "Total Cost : " << user->getChosenMenu()->getTotalCost() << std::endl;
        std::cout << "Overall Sweetness : " << user->getChosenMenu()->getOverallSweetness() << std::endl;
        std::cout << "Overall Sourness : " << user->getChosenMenu()->getOverallSourness() << std::endl;
        std::cout << "Overall Saltiness : " << user->getChosenMenu()->getOverallSaltiness() << std::endl;
        std::cout << "Overall Bitterness : " << user->getChosenMenu()->getOverallBitterness() << std::endl;
        std::cout << "Overall Savoriness : " << user->getChosenMenu()->getOverallSavoriness() << std::endl;
    }

    void MenuInterface::Suggesstion(float sweetness, float sourness, float saltiness, float bitterness, float savoriness){
        std::cout << "Suggesstion using lse" << std::endl;
    }

    void MenuInterface::Goodbye() {
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }

     
    