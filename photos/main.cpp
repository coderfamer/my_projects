#include "exiv2/exiv2.hpp"
#include <iostream>
#include <string>

class Phots : public Exiv2::ImageFactory
{

};
//! 
int main()
{
    std::string file = "./test.jpg";
    std::cout << "Hello Cmake!!!\n";

    Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(file);
    image.get();
    image->readMetadata();
    Exiv2::ExifData &exifData = image->exifData();
    Exiv2::ExifData::const_iterator end = exifData.end();
    for (auto i = exifData.begin(); i != end; ++i) {
        const char * tn = i->typeName();
        std::cout << std::setw(44) << std::setfill(' ') << std::left
                << i->key() << " " 
                << "0x" << std::setw(4) << std::setfill('0') << std::right
                << std::hex << i->tag() << " "
                << std::setw(9) << std::setfill(' ') << std::left
                << (tn ? tn : "Unknown") << " "
                << std::dec << std::setw(3)
                << std::setfill(' ') << std::right
                << i->count() << " "
                << std::dec << i->value() << std::endl;
    }

    // auto iter = exifData.begin();
    // for (;iter != exifData.end(); ++iter) {
    //     std::cout << iter->key() << "====>>" <<  *iter << std::endl;
    // }

    // std::cout << exifData["Exif.Image.DateTime"] << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSTimeStamp"] << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSLatitude"].toFloat() << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSLongitude"] << std::endl;
    // std::cout << *exifData["Exif.GPSInfo.GPSLongitude"].getValue() << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSLongitude"].toString() << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSLongitude"].toLong() << std::endl;
    // std::cout << exifData["Exif.GPSInfo.GPSLongitude"].toRational().first << std::endl;
    auto da = exifData["Exif.GPSInfo.GPSLongitude"];
    auto num = da.count();
    for (int i = 0; i < num; i++) {
        std::cout << da.toString(i) << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < num; i++) {
        std::cout << da.toLong(i) << " ";
    }
    std::cout << std::endl;



    return 0;
}
