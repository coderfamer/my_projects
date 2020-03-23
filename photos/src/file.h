#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef struct _file_info
{

}File;

class FileInfo 
{
    FileInfo(std::string name = " ") : m_folder_name(name){}

    void read_folder();

    void read_file_exif_info();


    inline std::vector<std::string> &get_filelist() { }

private:
    std::string m_folder_name;
};

#endif
