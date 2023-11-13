#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <ConverterLib/Parser/MessageConverter.h>
#include <QDir>

int main(int argc, char *argv[])
{
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};


    a.insert(a.begin(), b.begin(), b.end());
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, "\n"));

    converterLib::Message::MessageList list;

    {
        //1st msg
        converterLib::Message::TranslationPair m1TrPair = std::make_pair("en_Gb", "m1Translation");
        converterLib::Message m1("mId1", 2, "m1Comment", m1TrPair, 1);

        converterLib::Message::TranslationPair m2TrPair = std::make_pair("ru_Ru", "m2Translation");
        converterLib::Message m2("mId1", 2, "m1Comment", m2TrPair);
        m1.concatanate(m2);

        converterLib::Message::TranslationPair m3TrPair = std::make_pair("hv_HV", "m3Translation");
        converterLib::Message m3("mId1", 2, "m1Comment", m3TrPair);
        m1.concatanate(m3);

        list.push_back(m1);
    }

    {
        //1st msg
        converterLib::Message::TranslationPair m1TrPair = std::make_pair("en_Gb", "m1Translation");
        converterLib::Message m1("mId2", 2, "m2Comment", m1TrPair, 1);

        converterLib::Message::TranslationPair m2TrPair = std::make_pair("ru_Ru", "m2Translation");
        converterLib::Message m2("mId2", 2, "m2Comment", m2TrPair);
        m1.concatanate(m2);

        converterLib::Message::TranslationPair m3TrPair = std::make_pair("hv_HV", "m3Translation");
        converterLib::Message m3("mId2", 2, "m2Comment", m3TrPair);
        m1.concatanate(m3);

        list.push_back(m1);
    }


    QDir fullPath = QDir::currentPath();
    //converterLib::MessageConverter::writeXML(list, fullPath);


    converterLib::Message::MessageList messageReadList;
    QDir path = QDir::currentPath();
    QString FileName = path.absoluteFilePath("Strings.en-GB.resx");

    converterLib::MessageConverter::readXml(messageReadList, FileName);

    int i = 0;
    for(const auto &msg : messageReadList)
    {
        std::cout << "\n\n index: " << ++i << msg;
    }

    return 0;
}
