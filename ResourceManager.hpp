#pragma once
#include "Resource.hpp"

class ResourceManager
{
    public: 
        ResourceManager()  // konstruktor domy�lny
        {
        	cos = new Resource();
		}
        
        double get()  //metoda double get
        {
        	return cos->get();
		}
        
        ResourceManager(const ResourceManager& i)  // konstruktor kopiuj�cy
        {
        	cos = new Resource();
        	*cos = *(i.cos);	//kopiuj� warto��
		}
        
    	ResourceManager& operator=(const ResourceManager& i)  //kopiuj�cy operator przypisania
    	{
    		*cos = *i.cos;
    		return *this;  //gdy korzystamy z operatora przypisania korzystamy z return 
		}
		
		ResourceManager(ResourceManager&& i)  //konstruktor przenosz�cy
		{
			cos = (i.cos);
			i.cos = nullptr;  //nullptr to wska�nik pusty
		}
		
		ResourceManager& operator=(ResourceManager&& i)  //przenosz�cy operator przypisania
    	{
    		delete cos;
    		cos = i.cos;
    		i.cos = nullptr;
    		return *this;
		}
		
		~ResourceManager()
		{
			delete cos;
		}
		
    private: 
        Resource* cos; 
};
