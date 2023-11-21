#include <iostream>
using namespace std;

struct menu
{
    string name;
    int price;
    menu *next;
};

struct employee
{
    string name;
    int id;
    int salary;
    employee *next;
    employee *previous;
};

menu *menuHead = NULL;
employee *employeeHead = NULL;

void addMenu(string menuItem, int price)
{
    menu *newMenu = new menu;
    newMenu->name = menuItem;
    newMenu->price = price;
    newMenu->next = NULL;

    if (menuHead == NULL)
    {
        menuHead = newMenu;
    }
    else
    {
        menu *temp = menuHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newMenu;
    }
}

void addEmployee(string name, int id, int salary)
{
    employee *newEmp = new employee;
    newEmp->name = name;
    newEmp->id = id;
    newEmp->salary = salary;
    newEmp->next = NULL;

    if (employeeHead == NULL)
    {
        employeeHead = newEmp;
    }
    else
    {
        employee *temp = employeeHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmp;
    }
}

void displayMenu()
{
    menu *temp = menuHead;
    while (temp != NULL)
    {
        cout << temp->name << " - $" << temp->price << "\n";
        temp = temp->next;
    }
}

void displayEmployee()
{
    employee *temp = employeeHead;
    while (temp != NULL)
    {
        cout << "Name: " << temp->name << "\nID: " << temp->id << "\nSalary: " << temp->salary << "\n";
        temp = temp->next;
    }
}

int main()
{
    int optionsRole;

    while (1)
    {
        printf("\n\n\n");
        printf("Please choose an option\n");
        printf("1. Admin\n");
        printf("2. Customer\n");
        printf("3. Exit\n");

        while (1)
        {
            scanf("%d", &optionsRole);
            if (optionsRole >= 1 && optionsRole <= 3)
                break;
            else
            {
                printf("\n\n\n");
                printf("Please choose a valid option\n");
                printf("1. Admin\n");
                printf("2. Customer\n");
                printf("3. Exit\n");
            }
        }

        // admin option
        if (optionsRole == 1)
        {
            int adminOptions;
            printf("Please choose an option(admin)\n");
            printf("1. Add Menu\n");
            printf("2. Show Menu\n");
            printf("3. Add Employee\n");
            printf("4. Show Employee\n");
            printf("5. Exit\n");

            while (1)
            {
                scanf("%d", &adminOptions);
                if (adminOptions >= 1 && adminOptions <= 5)
                    break;
                else
                {
                    printf("Please choose a valid option(admin)\n");
                    printf("1. Add Menu\n");
                    printf("2. Show Menu\n");
                    printf("3. Add Employee\n");
                    printf("4. Show Employee\n");
                    printf("5. Exit\n");
                }
            }

            // Add menu
            if (adminOptions == 1)
            {
                int price;
                string name;
                printf("Enter an item name: ");
                cin >> name;
                printf("Enter an item price: ");
                cin >> price;
                addMenu(name, price);
                cout << "Item '" << name << "' added successfully\n";
            }
            else if (adminOptions == 2)
            {
                // show menu for admin
                printf("Here are menus: \n");
                displayMenu();
            }
            else if (adminOptions == 3)
            {
                // add employee option
                int salary;
                string name;
                int id;
                printf("Enter an employee name: ");
                cin >> name;
                printf("Enter an employee id: ");
                cin >> id;
                printf("Enter an employee salary: ");
                cin >> salary;
                addEmployee(name, id, salary);
                cout << "Employee '" << name << "' added successfully\n";
            }
            else if (adminOptions == 4)
            {
                printf("Here are Employees\n");
                // show employee for admin
                displayEmployee();
            }

            // if admin press exit key: he will be go to the start option again
            else if (adminOptions == 5)
            {
                break;
            }
        }
        // end of admin option

        // customer option start
        else if (optionsRole == 2)
        {
            int customerOptions;
        customerStart:
            customerOptions = customerOptions;
            printf("Please choose an option (user)\n");
            printf("1. Order\n");
            printf("2. Exit\n");
            scanf("%d", &customerOptions);

            switch (customerOptions)
            {

            case 1:
            {
                displayMenu();

                string customerName, itemName;
                int quantity;
                printf("Enter your name: ");
                cin >> customerName;
                printf("Enter your item name: ");
                cin >> itemName;
                cout << "How many " << itemName << " do you want: ";
                cin >> quantity;

                // show rightaway
                printf("Here is your bill:\n");
                cout << "Customer name: " << customerName << "\n";
                cout << "Ordered item name: " << itemName << "\n";
                cout << "Total price: " << (quantity * 50) << "\n";
                // Order from menu
            cout << "Thank you. Come back again\n";

                break;
            }

            case 2:
            {
                break;
            }
            default:
                printf("Please, select a valid option\n");
                goto customerStart;
                break;
            }
            break;
        }

        // customer option end

        // end the program
        else if (optionsRole == 3)
        {
            cout << "Thank you. Come back again\n";
            // return 0;
        }
    }

    return 0;
}
