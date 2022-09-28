#include <iostream>
#include <string>
#include <algorithm>

class Playlist {
    private:
    int size;
    int sizeUsed;
    std::string *playlistArray;

    public:
    Playlist();
    ~Playlist();

    void create(int size_p);
    std::string insert(std::string newSong);
    std::string play(int n);
    std::string erase(int n);
};



Playlist::Playlist(){
    size = 0;
    playlistArray = 0;
    sizeUsed = 0;
}

Playlist::~Playlist() {
    delete [] playlistArray;
}

void Playlist::create(int size_p) {
    this->size = size_p;
    this->playlistArray = new std::string[size]; 
    this->sizeUsed = 0;
}

//inserts newSong in the playlistArray after checking all conditions amd returns a string
std::string Playlist::insert(std::string newSong) {
    int size = this->size;
    
    if(this->sizeUsed >= this->size) {
        return "can not insert " + newSong;
    }

    int semiColon = newSong.find_first_of(';');
    std::string title = newSong.substr(0, semiColon);
    std::string artist = newSong.substr(semiColon + 1, newSong.length());
    
    if(title == "My Heart Will Go On"){
        return "can not insert " + newSong;
    }
    else if((title == "Muskrat Love") && (artist == "Captain and Tennille")){
        return "can not insert " + newSong;
    }
    
    bool present = std::find(this->playlistArray, this->playlistArray+this->sizeUsed, newSong) != this->playlistArray+this->sizeUsed;

    if(present){
        return "can not insert " + newSong;
    }
    else {
        this->playlistArray[this->sizeUsed] = newSong;
        this->sizeUsed += 1;
    }
    

    return "success"; 
}

std::string Playlist::play(int n) {
    if((n >= 0) && (n < this->sizeUsed)){
        return "played " + std::to_string(n) + " " + this->playlistArray[n];
    }
    else {
        return "can not play " + std::to_string(n);
    }
}

std::string Playlist::erase(int n) {
    if((n >= 0) && (n < this->sizeUsed)){
        int i = n;
        for(i; i < this->sizeUsed - 1 ; i++)
        {   
            this->playlistArray[i] = this->playlistArray[i+1];
        }
        this->sizeUsed -= 1;
        return "success";
    }
    else {
        return "can not erase " + std::to_string(n);
    }
}

int main() {
    bool createdArray = false;
    Playlist p1;

    do {
        std::string inp;
        std::getline(std::cin, inp);
        char firstLetter = inp[0];

        if(inp.length() == 0){
            break;
        }
        else {
            std::string input = inp.substr(2);
            
            if((firstLetter == 'm') && (createdArray == false)){
                int n = stoi(input);
                p1.create(n);
                createdArray = true;
                std::cout << "success" << std::endl;
            }
            else if((firstLetter == 'i') && (createdArray == true)){
                std::cout << p1.insert(input) << std::endl;
            }
            else if((firstLetter == 'p') && (createdArray == true)){
                int n = stoi(input);
                std::cout << p1.play(n) << std::endl;
            }
            else if((firstLetter == 'e') && (createdArray == true)){
                int n = stoi(input);
                std::cout << p1.erase(n) << std::endl;
            }
        }
            
    } while(true);
}    