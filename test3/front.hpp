#ifndef FRONT_HPP
#define FRONT_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>


enum Food_class{
    fruit,
    vegetable,
    drink,
    dairy,
    canned,
    meat,
    fish,
    sweet,
    nut,
    unspecified,
    other
};

enum Priority{
    red,
    orange,
    green
};

////////////////////////////////////////////////////////////////////////////

class Ingredient{
public:
    Ingredient(std::string *name);
    Ingredient(std::string *name, int *quantity,Food_class *category, std::string *expiry_date);
    ~Ingredient();
    void set_FoodClass(Food_class *category);
    Food_class get_FoodClass();
    void set_Quantity(int *quantity);
    int get_Quantity();
    void set_priority(Priority priority_level);
    Priority get_priority();
    std::string get_name() const;
    bool operator==(const Ingredient& other) const;
    void saveToJsonFile(const std::string& fileIngredient);

    

private:
    std::string *name = new std::string;
    Food_class *category = new Food_class;
    int *quantity = new int;
    std::string *expiry_date = new std::string;
    Priority priority_level;
};

////////////////////////////////////////////////////////////////////////////

class Fridge {
public:
    Fridge();
    Fridge(std::list<Ingredient> init_list);
    ~Fridge();
    void set_list(std::list<Ingredient> new_list);
    std::list<Ingredient> get_list();
    void add_elt(Ingredient elt);

    Ingredient pop_elt(Ingredient *getit);
    void saveToJsonFile(const std::string& fileFridge);

    
    


private:
    std::list<Ingredient>* ingredient_list;
};

////////////////////////////////////////////////////////////////////////////

class User{
public:
<<<<<<< HEAD
    User(std::string *username, std::string *password);
    ~User();
=======
    User();
    ~User()
    void set_username(std::string username);
>>>>>>> 4f5cca9fb27ec4cafd9d977ddfcd38dfc02d060a
    std::string get_username();
    bool check_password(std::string *input_password);
    void set_telegram(std::string *telegram);
    std::string get_telegram();

private:
    std::string* username = new std::string;
    std::string* password = new std::string;
    std::string* telegram_username = new std::string;
    Fridge* user_fridge = new Fridge();
};

////////////////////////////////////////////////////////////////////////////

class Offer {
public:
    Offer();
    ~Offer();
    void set_price(double price);
    double get_price();
    void set_user(User user);
    User get_user();

private:
    std::list<Ingredient> ingredient_list;
    double price;
    User username;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // FRONT_HPP
