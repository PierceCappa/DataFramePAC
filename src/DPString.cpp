#include "DPString.h"


namespace DataPAC
{
	//-----------------------Initialization Methods BEGIN-----------------------

    DPString::DPString(){this->Value = new char('\0');}

    DPString::DPString(char* newValue, int length)
    {
        this->Value = new char [length + 1];
        strcpy(this->Value,newValue);
        this->Value[length] = '\0';
    }

    DPString::DPString(std::string newValue)
    {
        int len = newValue.size();
        this->Value = new char [len];
        strcpy(this->Value, newValue.c_str());
        this->Value[len - 1] = '\0';
    }

    DPString::DPString(DPString* newValue)
    {
        int len = strlen(newValue->Value)+1;
        this->Value = new char [len];
        strcpy(this->Value,newValue->Value);
        this->Value[len] = '\0';
    }

    DPString::~DPString()
    {
        free(this->Value);
    }

    NodeValue* DPString::createNewNode(){return new DPString();}
    
    NodeValue* DPString::createNewNode(char* newValue, int length){return new DPString(newValue, length);}

    NodeValue* DPString::createNewNode(void* newValue)
    {
        try
        {
            return new DPString((char*)newValue, strlen((char*)newValue));
        }
        catch(std::invalid_argument)
        {
            return NULL;
        }    
    }

    NodeValue* DPString::createNewNode(NodeValue newValue){return new DPString(newValue.toString());}

    NodeValue* DPString::createNewNode(int newValue){return new DPString(std::to_string(newValue));}

    NodeValue* DPString::createNewNode(float newValue){return new DPString(std::to_string(newValue));}
        
    NodeValue* DPString::createNewNode(std::string newValue){return new DPString(newValue);}

	//-----------------------Initialization Methods END-----------------------
    //-----------------------Set Value Methods BEGIN-----------------------

    bool DPString::setValue(std::string newValue)    
    {
        try
        {
            this->deleteCurrentString();
            int len = newValue.size() + 1;
            this->Value = new char [len];
            strcpy(this->Value, newValue.c_str());
            this->Value[len - 1] = '\0';
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPString::setValue(char* newValue)
    {
        try
        {
            this->deleteCurrentString();
            int len = strlen(newValue) + 1;
            this->Value = new char [len];
            strcpy(this->Value, newValue);
            this->Value[len - 1] = '\0';
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPString::setValue(float newValue)
    {
        try
        {
            return this->setValue(std::to_string(newValue));
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }
    bool DPString::setValue(int newValue)
    {
        try
        {
            return this->setValue(std::to_string(newValue));
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }
    bool DPString::setValue(NodeValue newValue)
    {
        try
        {
            this->deleteCurrentString();
            int len = newValue.toString().size()+1;
            this->Value = new char [len];
            strcpy(this->Value,newValue.toString().c_str());
            this->Value[len] = '\0';
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }
    bool DPString::setValue(void* newValue)
    {
        try
        {
            this->deleteCurrentString();
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    //-----------------------Set Value Methods END-----------------------
	//-----------------------General node value operators for overide BEGIN-----------------------

    ValueType DPString::getType(){return ValueType::String;}

    std::string DPString::toString(){return std::string(this->Value);}

    void* DPString::getValue(){return (void*)this->Value;}

    float DPString::toFloat(){return 0.0;}

    int DPString::toInt(){return 0;}

    bool DPString::isNumeric(){return false;}

    bool DPString::isContinous(){return true;}

    bool DPString::isDiscrete(){return false;}

    unsigned int DPString::toHash(){return this->hash();}

	//-----------------------General node value operators for overide END-----------------------
    //-----------------------Object Operators Methods BEGIN-----------------------

    bool DPString::operator==(NodeValue* rightSide)
    {
        if(rightSide->getType() == ValueType::String)
        {
            return this->Value == rightSide->getValue();
        }
        return false;
    }

    bool DPString::operator==(float rightSide){return false;}

    bool DPString::operator==(int rightSide){return false;}

    bool DPString::operator==(char* rightSide){return this->Value == rightSide;}

    bool DPString::operator==(std::string rightSide){return this->Value == rightSide;}

    bool DPString::operator==(void* rightSide)
    {
        try
        {
            return rightSide == (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }


    bool DPString::operator!=(NodeValue* rightSide)
    {
        if(rightSide->getType() == ValueType::String)
        {
            return this->Value != rightSide->getValue();
        }
        return true;
    }

    bool DPString::operator!=(float rightSide){return true;}

    bool DPString::operator!=(int rightSide){return true;}

    bool DPString::operator!=(char* rightSide){return this->Value != rightSide;}

    bool DPString::operator!=(std::string rightSide){return this->Value != rightSide;}

    bool DPString::operator!=(void* rightSide)
    {
        try
        {
            return rightSide != (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return true;
        }
    }



    bool DPString::operator<(NodeValue* rightSide)
    {
        if(rightSide->getType() < ValueType::String)
        {
            return this->Value < rightSide->getValue();
        }
        return false;
    }
    
    bool DPString::operator<(float rightSide){return false;}

    bool DPString::operator<(int rightSide){return false;}

    bool DPString::operator<(char* rightSide){return this->Value < rightSide;}

    bool DPString::operator<(std::string rightSide){return this->Value < rightSide;}

    bool DPString::operator<(void* rightSide)
    {
        try
        {
            return rightSide < (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }



    bool DPString::operator>(NodeValue* rightSide)
    {
        if(rightSide->getType() > ValueType::String)
        {
            return this->Value > rightSide->getValue();
        }
        return false;
    }
    
    bool DPString::operator>(float rightSide){return false;}

    bool DPString::operator>(int rightSide){return false;}

    bool DPString::operator>(char* rightSide){return this->Value > rightSide;}

    bool DPString::operator>(std::string rightSide){return this->Value > rightSide;}

    bool DPString::operator>(void* rightSide)
    {
        try
        {
            return rightSide > (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }



    bool DPString::operator<=(NodeValue* rightSide)
    {
        if(rightSide->getType() <= ValueType::String)
        {
            return this->Value <= rightSide->getValue();
        }
        return false;
    }

    bool DPString::operator<=(float rightSide){return false;}

    bool DPString::operator<=(int rightSide){return false;}

    bool DPString::operator<=(char* rightSide){return this->Value <= rightSide;}

    bool DPString::operator<=(std::string rightSide){return this->Value <= rightSide;}

    bool DPString::operator<=(void* rightSide)
    {
        try
        {
            return rightSide <= (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }



    bool DPString::operator>=(NodeValue* rightSide)
    {
        if(rightSide->getType() >= ValueType::String)
        {
            return this->Value >= rightSide->getValue();
        }
        return false;
    }

    bool DPString::operator>=(float rightSide){return false;}

    bool DPString::operator>=(int rightSide){return false;}

    bool DPString::operator>=(char* rightSide){return this->Value >= rightSide;}

    bool DPString::operator>=(std::string rightSide){return this->Value >= rightSide;}

    bool DPString::operator>=(void* rightSide)
    {
        try
        {
            return rightSide >= (char*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }





    NodeValue DPString::operator+(NodeValue* rightSide)
    {
        if(rightSide->getType() == ValueType::String)
        {
            return DPString(strcat(this->Value, rightSide->toString().c_str()));
        }
        return DPString();
    }

    float DPString::operator+(float rightSide){return 0;}

    float DPString::operator+(int rightSide){return 0;}

    char* DPString::operator+(char* rightSide)
    {
        return strcat(this->Value, rightSide);
    }

    std::string DPString::operator+(std::string rightSide)
    {
        return std::string(this->Value + rightSide);
    }

    void* DPString::operator+(void* rightSide)
    {return rightSide;}



    NodeValue DPString::operator-(NodeValue* rightSide)
    {return DPString();}

    float DPString::operator-(float rightSide){return 0;}

    float DPString::operator-(int rightSide){return 0;}

    void* DPString::operator-(void* rightSide)
    {
        return NULL;
    }



    NodeValue DPString::operator*(NodeValue* rightSide)
    {return DPString();}
    
    float DPString::operator*(float rightSide){return false;}

    float DPString::operator*(int rightSide){return false;}

    void* DPString::operator*(void* rightSide)
    {return NULL;}



    NodeValue DPString::operator/(NodeValue* rightSide)
    {return DPString();}
    
    float DPString::operator/(float rightSide){return 0.0;}

    float DPString::operator/(int rightSide){return 0;}

    void* DPString::operator/(void* rightSide)
    {return NULL;}

    

    NodeValue DPString::operator%(NodeValue* rightSide)
    {return DPString();}
    
    float DPString::operator%(float rightSide){return 0.0;}

    float DPString::operator%(int rightSide){return 0;}

    void* DPString::operator%(void* rightSide)
    {return NULL;}

    //-----------------------Object Operators Methods END-----------------------
    //-----------------------String Value Operators BEGIN-----------------------

    void DPString::deleteCurrentString()
    {
        free(this->Value);
    }

    //djb2
    //http://www.cse.yorku.ca/~oz/hash.html
    unsigned int DPString::hash()
    {
        unsigned long hash = 5381;
        int c;
        while (c = *this->Value++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash;
    }

    //-----------------------String Value Operators END-----------------------
}