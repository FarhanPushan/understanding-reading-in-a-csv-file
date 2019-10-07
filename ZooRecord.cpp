#include "ZooRecord.hpp"




// ZooRecord::ZooRecord() //ArrayBag()
// {
// }

/**parameterized constructor 
 * @pre the input file is expected to be in CSV     
    (comma separated value) format as: "animal_name,hair,feathers,eggs,milk,
    airborne,aquatic,predator,toothed, backbone,breathes,venomous,fins,legs,tail,
    domestic,catsize,class_type\n"
@param input_file_name the name of  the input file
    @post adds Animal objects to record as per the data in the input file     **/  
 
 
ZooRecord::ZooRecord(std::string input_file_name)
{
    
    
    
    std::ifstream input_file; // file pointer
    input_file.open(input_file_name); //open an existing file

    if(input_file.fail())
    {
        std::cerr << "Failed to read in file." << std::endl;
        exit(1);
    }

    std::string junk; //created a variable junk here with the intention of placing stuff 
                        //I don't want to use into this
    getline(input_file, junk, '\n'); //taking stream from input file, only untill end of line (eol) , 
                                        //placeing it into junk
    int count = 0; //initializing a variable so I don't have a memory leak 
    //this was a test to see if I was printing intended line
    //std::cout << junk <<std::endl; //printing out first line stored in string junk taken from stream
                                   
    //Recall! the first line from zoo.csv file :animal_name,hair,feathers,eggs,milk,airborne,aquatic,
    ///predator,toothed,backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type
    /// is all stored in junk so now I'm about to work with the next line. I want to store
    /// the next line into another string variable; place
    
    while(count < 101)
    {

    std::string place;
    getline(input_file, place,'\n');
    std::stringstream read(place); //taking sec line stream, turning it into a string stream
    std::string animal_name; //declared a string animal_name to place the names ONLY into
    getline(read,animal_name,','); //this has parameters source, location, delimiter, which should give
                                    //me the name of the animals ONLY
    //std::cout << animal_name << std::endl;//I can now print out all the names of the animals ONLY in my zoo.csv
    
     for(int i = 0; i < 6; i++)
    {
        getline(read, junk, ',');
        //std::cout << "hello";
    }                               //all helps me parse through 
    std::string predator;
    getline(read, predator,',');
    //std::cout << animal_name << " " << predator<< std::endl;
    
    for(int i = 0; i < 7; i++)
    {
        getline(read, junk,',');
    }

    std::string domestic;
    getline(read, domestic,',');
    std::cout << animal_name << " " << predator<< " "<< domestic << std::endl;
    
    count++;


   


    } //i can add all the lines and print them from csv.

    


/**
    //OK! so far I've got access to the first two lines in .csv
    ///now I need access to specific parts in my second line bc thats the information
    ///i want to store
    std::stringstream read(place);//this allows me to work with the second line in zoo in a diff way
    ///I'm not quite clear on what that is yet...
    std::string animal_name;
    getline(read,animal_name,','); //we know that the first spot in our line is a name, we know that
    ///the delimiter basically means the end, 
    std::cout << animal_name << std::endl;//gives us the first name in our line


    for(int i = 0; i < 7; i++)
    {
        getline(read, junk, ',');
    }                               //all helps me parse through 
    std::string predator;
    getline(read, predator,',');
    std::cout << predator<< std::endl;


    for(int i = 0; i < 8 ; i++)
    {
        getline(read, junk,',');
    }

    std::string domestic;
    getline(read, domestic,',');
    std::cout << domestic << std::endl;

    Animal a(animal_name,(domestic=="1"),predator=="1"); //making an animal object a
    // //why are the values in the param for this 0 or 1? I understand that they are bools
    add(a);//added to ZooRecord//display ZooRecords contents through main

    std::string secline;
    getline(input_file, secline, '\n');
    std::cout<<secline<<std::endl;

    std::stringstream read2(secline);
    std::string secAnimalName;
    getline(read2, secAnimalName, ',');
    std::cout<<secAnimalName<<std::endl;

    for(int i = 0; i < 7; i++)
    {
        getline(read2, junk, ',');
    }                               //all helps me parse through 
    std::string predator2;
    getline(read2, predator2,',');
    std::cout << predator2<< std::endl;


    for(int i = 0; i < 8 ; i++)
    {
        getline(read2, junk,',');
    }

    std::string domestic2;
    getline(read2, domestic2,',');
    std::cout << domestic2 << std::endl;

    Animal b(secAnimalName,(domestic2=="1"),predator2=="1");

    add(b);


**/
}

/**@post displays all animals in record, one per line by calling animal's display method” **/ 

void ZooRecord::display()
{
    for(size_t i = 0; i < item_count_; i++)
    {
        items_[i].display();
    }
} 
