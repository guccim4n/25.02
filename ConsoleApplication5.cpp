#include <iostream>
#include <string>
using namespace std;

class fruit
{
private:
    float weight;
    int price;
    string name;
    string color;

public:
    fruit(float weightValue = 0.0, int priceValue = 0, string nameValue = "", string colorValue = "")
    {
        this->weight = weightValue;
        this->price = priceValue;
        this->name = nameValue;
        this->color = colorValue;
    }

    string get_name() const { return name; }
    string get_color() const { return color; }
    int get_price() const { return price; }
    float get_weight() const { return weight; }

    void set_name(string name) { this->name = name; }
    void set_color(string color) { this->color = color; }
    void set_price(int price) { this->price = price; }
    void set_weight(float weight) { this->weight = weight; }

    float cost() const
    {
        return (weight / 100.0) * price;
    }

    void print() const
    {
        cout << "Name: " << name
            << "\nColor: " << color
            << "\nPrice: " << price << "$"
            << "\nWeight: " << weight << "kg"
            << "\nCost: " << cost() << "$\n";
    }

    static void menu()
    {
        cout << "\nMenu:\n";
        cout << "1) Adding an empty object to an array\n";
        cout << "2) Adding an object with data\n";
        cout << "3) Editing any field\n";
        cout << "4) Output information about all objects to the console\n";
        cout << "5) Sorting an array\n";
        cout << "6) Program shutdown\n";
    }

    static void adding(fruit** fruits, int& count, int& capacity)
    {
        if (count >= capacity)
        {
            capacity *= 2;
            fruit* new_fruits = new fruit[capacity];
            for (int i = 0; i < count; ++i)
            {
                new_fruits[i] = (*fruits)[i];
            }
            delete[] * fruits;
            *fruits = new_fruits;
        }
        (*fruits)[count++] = fruit();
        cout << "Empty fruit added.\n";
    }

    static void ADD(fruit** fruits, int& count, int& capacity)
    {
        if (count >= capacity)
        {
            capacity *= 2;
            fruit* new_fruits = new fruit[capacity];
            for (int i = 0; i < count; ++i)
            {
                new_fruits[i] = (*fruits)[i];
            }
            delete[] * fruits;
            *fruits = new_fruits;
        }
        string name, color;
        float weight;
        int price;

        cout << "Enter fruit name: ";
        cin >> name;
        cout << "Enter fruit color: ";
        cin >> color;
        cout << "Enter fruit weight (in kg): ";
        cin >> weight;
        cout << "Enter fruit price (per kg): ";
        cin >> price;

        (*fruits)[count++] = fruit(weight, price, name, color);
        cout << "Fruit added with data.\n";
    }

    static void Editing(fruit* fruits, int count)
    {
        int index;
        cout << "Enter the index of the fruit to edit: ";
        cin >> index;

        if (index >= 0 && index < count)
        {
            cout << "Select field to edit:\n";
            cout << "1. Name\n";
            cout << "2. Color\n";
            cout << "3. Weight\n";
            cout << "4. Price\n";
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter new name: ";
                cin >> name;
                fruits[index].set_name(name);
                break;
            }
            case 2:
            {
                string color;
                cout << "Enter new color: ";
                cin >> color;
                fruits[index].set_color(color);
                break;
            }
            case 3:
            {
                float weight;
                cout << "Enter new weight (in kg): ";
                cin >> weight;
                fruits[index].set_weight(weight);
                break;
            }
            case 4:
            {
                int price;
                cout << "Enter new price (per kg): ";
                cin >> price;
                fruits[index].set_price(price);
                break;
            }
            default:
                cout << "Invalid choice.\n";
                break;
            }
        }
        else
        {
            cout << "Invalid index.\n";
        }
    }

    static void Output_to_the_console(fruit* fruits, int count)
    {
        for (int i = 0; i < count; ++i)
        {
            cout << "Fruit " << i << ":\n";
            fruits[i].print();
            cout << "-----------------\n";
        }
    }

    static void Sorting_an_array(fruit* fruits, int count)
    {
        cout << "Select sorting criteria:\n";
        cout << "1. Name\n";
        cout << "2. Color\n";
        cout << "3. Weight\n";
        cout << "4. Price\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Sorting_an_array_Name(fruits, count);
            break;
        case 2:
            Sorting_an_array_Color(fruits, count);
            break;
        case 3:
            Sorting_an_array_Weight(fruits, count);
            break;
        case 4:
            Sorting_an_array_Price(fruits, count);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    // Методы для сортировки
    static void Sorting_an_array_Name(fruit* fruits, int count)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = 0; j < count - i - 1; ++j)
            {
                if (fruits[j].get_name() > fruits[j + 1].get_name())
                {
                    fruit temp = fruits[j];
                    fruits[j] = fruits[j + 1];
                    fruits[j + 1] = temp;
                }
            }
        }
    }

    static void Sorting_an_array_Color(fruit* fruits, int count)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = 0; j < count - i - 1; ++j)
            {
                if (fruits[j].get_color() > fruits[j + 1].get_color())
                {
                    fruit temp = fruits[j];
                    fruits[j] = fruits[j + 1];
                    fruits[j + 1] = temp;
                }
            }
        }
    }

    static void Sorting_an_array_Weight(fruit* fruits, int count)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = 0; j < count - i - 1; ++j)
            {
                if (fruits[j].get_weight() > fruits[j + 1].get_weight())
                {
                    fruit temp = fruits[j];
                    fruits[j] = fruits[j + 1];
                    fruits[j + 1] = temp;
                }
            }
        }
    }

    static void Sorting_an_array_Price(fruit* fruits, int count)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = 0; j < count - i - 1; ++j)
            {
                if (fruits[j].get_price() > fruits[j + 1].get_price())
                {
                    fruit temp = fruits[j];
                    fruits[j] = fruits[j + 1];
                    fruits[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    int capacity = 10;
    int count = 0;
    fruit* fruits = new fruit[capacity];

    int choice;
    while (true)
    {
        fruit::menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            fruit::adding(&fruits, count, capacity);
            break;
        case 2:
            fruit::ADD(&fruits, count, capacity);
            break;
        case 3:
            fruit::Editing(fruits, count);
            break;
        case 4:
            fruit::Output_to_the_console(fruits, count);
            break;
        case 5:
            fruit::Sorting_an_array(fruits, count);
            break;
        case 6:
            delete[] fruits;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
