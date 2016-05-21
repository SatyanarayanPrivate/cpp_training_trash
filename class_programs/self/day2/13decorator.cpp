#include <iostream>

using namespace std;


class iLogger   //Interface Class
{
public:
    virtual void LogMessage(char* msg)=0;
};


class NullLogger:public iLogger
{
public:
    void LogMessage(char *Mess)
    {
        //do nothing
    }    
};


class LoggerHelper:public iLogger
{
    iLogger *il;
public:
    LoggerHelper(iLogger *il):il(il)
    {
    }
    
    void LogMessage(char *msg)
    {
        il -> LogMessage(msg);
    }
};


class ConsoleLogger:public LoggerHelper
{
public:
    ConsoleLogger(iLogger *il):LoggerHelper(il)
    {
    }
    void LogMessage (char *msg)
    {
        cout << "ConsoleLogger msg=" << msg << endl;
        LoggerHelper::LogMessage(msg);
    }
};

class ServiceLogger:public LoggerHelper
{
public:
    ServiceLogger(iLogger *il):LoggerHelper(il)
    {
    }
    void LogMessage (char *msg)
    {
        cout << "ServiceLogger msg=" << msg << endl;
        LoggerHelper::LogMessage(msg);
    }
};

class FileLogger:public LoggerHelper
{
public:
    FileLogger(iLogger *il):LoggerHelper(il)
    {
    }
    void LogMessage (char *msg)
    {
        cout << "FileLogger msg=" << msg << endl;
        LoggerHelper::LogMessage(msg);
    }
};

class LoggerFactory
{
public:
    static iLogger * CreateLoggers()
    {
        return new ServiceLogger(new ConsoleLogger(new FileLogger(new NullLogger())));
    }
};



int main()
{
    cout << "Business Started...." << endl;
    iLogger *il=LoggerFactory::CreateLoggers();
    //if(il!=NULL)
    il->LogMessage((char *)"India is great");
    
    cout << "Business end..." << endl;
    
    //if(il!=NULL)
    il->LogMessage((char *)"India wins WC");
}

