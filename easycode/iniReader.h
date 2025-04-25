#ifndef WEBSERVER_EASYCODE_INIREADER_H_
#define WEBSERVER_EASYCODE_INIREADER_H_
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
class iniReader{
public:
    static std::string GetValue(
        const std::string& strGroupName , const std::string& strKey ,const std::string& strFilePath){
        boost::property_tree::ptree objPTree;
        boost::property_tree::ini_parser::read_ini(strFilePath, objPTree);
        return objPTree.get<std::string>(strGroupName+"." + strKey);
    }
};

#endif //WEBSERVER_EASYCODE_INIREADER_H_
