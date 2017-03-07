#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Zoo
{
    public:
        struct InfoAboutAnimals
        {
           	string  animal_name;
            int num_of_cell;
          	string favourite_food;
            bool give_food_to_animal;
        };

    private:
        int num_of_animals;
        string gurdian_name ;
        string start_work_time ;
        string end_work_time ;

        InfoAboutAnimals *struct_infoAboutAnimals;

    public:
        Zoo(int var_num_of_animals, string var_gurdian_name, string var_start_work_time, string var_end_work_time)
        {	
            num_of_animals = var_num_of_animals;
			struct_infoAboutAnimals = new InfoAboutAnimals[num_of_animals];
         
            gurdian_name=var_gurdian_name;  
            
            start_work_time= var_start_work_time;
            
            end_work_time=var_end_work_time;

        }

        void SetAnimalsInfo(string  struct_animal_name, int struct_number_of_animal_cell, string  struct_favourite_food, bool struct_give_food_to_animal, int count)
        {
        struct_infoAboutAnimals[count].animal_name=struct_animal_name;
            
        struct_infoAboutAnimals[count].favourite_food=struct_favourite_food;
          
		struct_infoAboutAnimals[count].num_of_cell = struct_number_of_animal_cell;
        
		struct_infoAboutAnimals[count].give_food_to_animal = struct_give_food_to_animal;
        }

        void ChangeGurdian(string new_gurdian_name)
        {
            gurdian_name="";
            gurdian_name=new_gurdian_name;
            
        }

        //Error of search
        void SearchAnimalToGiveFood(string animal_name_to_check, int num_of_cell_to_check)
        {
            int check_animals_match = num_of_animals;

            for(int i = 0; i < num_of_animals; i++)
            {
                if( (animal_name_to_check==struct_infoAboutAnimals[i].animal_name) && (num_of_cell_to_check == struct_infoAboutAnimals[i].num_of_cell) )
                {
                    if(struct_infoAboutAnimals[i].give_food_to_animal)
                    {
                        cout << "Animal not hungry" << endl<<endl<<endl;
                        break;
                    }
                    else
                    {
                        struct_infoAboutAnimals[i].give_food_to_animal = true;
                         cout << "We give foot to animal " << endl<<endl<<endl;
                        break;
                    }
                }
                else
                {
                    check_animals_match--;
                }
            }

            if(check_animals_match == 0)
            {
                cout << "Animals with this name and cell number not found" << endl<<endl<<endl;
            }
        }

        void GetInfoAboutZoo()
        {
            cout << "Start work time: " << start_work_time << endl;
            cout << "End work time: " << end_work_time << endl;
            cout << "Gurdian name: " << gurdian_name << endl;
 			cout << "==========================================================" << endl;
            for(int i = 0; i < num_of_animals; i++)
            {
                cout << "Animal name: " << struct_infoAboutAnimals[i].animal_name << endl;
                cout << "Number of animal cell: " << struct_infoAboutAnimals[i].num_of_cell << endl;
                cout << "Animal's favourite food: " << struct_infoAboutAnimals[i].favourite_food << endl;
                cout << "Give food to animal: " << struct_infoAboutAnimals[i].give_food_to_animal << endl;
                cout << "==========================================================" << endl;
            }
        }

};

int main()
{
    //Variables for menu
    int chose_from_menu;
    int num_of_cell_to_check;
    string animal_name_to_check;

   	string struct_animal_name;
    int struct_number_of_animal_cell;
   	string struct_favourite_food ;
    bool struct_give_food_to_animal;

    int var_num_of_animals;
    string var_start_work_time;
    string var_end_work_time ;
    string var_gurdian_name ;

    int count;

    cout << "Enter number of animals: "; cin >> var_num_of_animals;
    cout << "Enter gurdian's name: "; cin >> var_gurdian_name;
    cout << "Enter start work time: "; cin >> var_start_work_time;
    cout << "Enter end work time: "; cin >> var_end_work_time;

    Zoo obj_Zoo = Zoo(var_num_of_animals, var_gurdian_name, var_start_work_time, var_end_work_time);

    //system("cls");

    for(count = 0; count < var_num_of_animals; count++)
    {
        cout << "Animal name " <<count+1<<": "; cin >>      struct_animal_name;
        cout << "Number of animal cell "<<count+1<<": ";    cin >> struct_number_of_animal_cell;
        cout << "Animal's favourite food "<<count+1<<":";  cin >> struct_favourite_food;
        cout << "Give food to animal "<<count+1<<": ";      cin >> struct_give_food_to_animal;

        obj_Zoo.SetAnimalsInfo(struct_animal_name, struct_number_of_animal_cell, struct_favourite_food, struct_give_food_to_animal, count);

        struct_animal_name=" ";
        struct_favourite_food=" ";
        struct_give_food_to_animal = false;

       // system("cls");
    }

    do
    {
      //  system("cls");

        cout << "1.Change gurdian" << endl;
        cout << "2.Give food to animal" << endl;
        cout << "3.Show information about zoo" << endl;
        cout << "0.Exit" << endl;
        cin >> chose_from_menu;

     

        switch(chose_from_menu)
        {
            case 1:
                {
                    //system("cls");

                    var_gurdian_name=" ";

                    cout << "Enter new gurdian name: "; cin >> var_gurdian_name;
                    

                    obj_Zoo.ChangeGurdian(var_gurdian_name);

                    break;
                }

            case 2:
                {
                   // system("cls");

                    cout << "Enter animal's name: "; cin >> animal_name_to_check;
                    cout << "Enter animal's cell: "; cin >> num_of_cell_to_check;

                    obj_Zoo.SearchAnimalToGiveFood(animal_name_to_check, num_of_cell_to_check);

                    animal_name_to_check=" ";

                    break;
                }

            case 3:
                {
					//system("cls");
                    obj_Zoo.GetInfoAboutZoo();

                    break;
                }

            default:
                {
                    //system("cls");

                    cout << "There is no item with this number in menu!" << endl;
                    cout << "===============================================" << endl;
                    break;
                }
        }

    }while(chose_from_menu != 0);

    return 0;
}
