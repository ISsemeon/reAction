#include <iostream>

#include <ConverterLib/Parser/MessageConverter.h>


int main(int argc, char *argv[])
{

    converterLib::Message::MessageList messageReadList;

    QDir path = QDir::currentPath();
    QString FileName = path.absoluteFilePath("G7_localization_hr-HR_20230714.xlsx");
    QString FileName2 = path.absoluteFilePath("test.xlsx");

    converterLib::MessageConverter::readXLSX(messageReadList, FileName);


    std::cout << "MESSAGE LIST SIZE: " << messageReadList.size();

//    for(const auto &msg : messageReadList)
//    {
//        std::cout << "before: "<< msg;
//    }

    converterLib::MessageConverter::writeXLSX(messageReadList, FileName2);

    return 0;
}
