#include <iostream>
#include <id3v2lib.h>
#include <ostream>
int main(int argc, char* argv[])
{
    //1: Ensure proper argument
    if (argc == 1)
    {
        std::cout << "Please pass in a file as an argument" << std::endl;
        return 1;
    }
    if (argc > 2)
    {
        std::cout << "ERROR: Too many arguments" << std::endl;
        return 1;
    }

    //2: Check if argument is a valid file
    ID3v2_Tag* tag = ID3v2_read_tag(argv[1]);
    if(tag == NULL)
    {
        std::cout << "ERROR: Not an mp3 file" << std::endl;
        return 1;
    }

    //3: Display file info
    //title
    //artist
    //album
    //year

    bool quit = false;
    while (!quit)
    {
        system("clear");

        ID3v2_TextFrame* title_frame = ID3v2_Tag_get_title_frame(tag);
        printf("title: %s\n", title_frame->data->text);

        ID3v2_TextFrame* artist_frame = ID3v2_Tag_get_artist_frame(tag);
        printf("artist: %s\n", artist_frame->data->text);
        
        ID3v2_TextFrame* album_artist_frame = ID3v2_Tag_get_album_artist_frame(tag);
        printf("album_artist: %s\n", album_artist_frame->data->text);

        ID3v2_TextFrame* album_frame = ID3v2_Tag_get_album_frame(tag);
        printf("album: %s\n", album_frame->data->text);

        ID3v2_TextFrame* year_frame = ID3v2_Tag_get_year_frame(tag);
        printf("year: %s\n", year_frame->data->text);

        std::cout << "Make a selection:" << std::endl;
        int choice;
        std::cin >> choice;
        std::cout << choice << std::endl;
        if (!std::cin)
        {
            choice = -1;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }

        switch (choice)
        {
            case 0:
                quit = true;
                break;
            default:
                std::cout << "ERROR: Not a valid input" << std::endl;
                break;
        }
    }
    
    return 0;
}
