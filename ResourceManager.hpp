#pragma once
#include "Resource.hpp"

class ResourceManager
{
    public: 
        ResourceManager()  // konstruktor domyœlny
        {
        	cos = new Resource();
		}
        
        double get()  //metoda double get
        {
        	return cos->get();
		}
        
        ResourceManager(const ResourceManager& i)  // konstruktor kopiuj¹cy
        {
        	cos = new Resource();
        	*cos = *(i.cos);	//kopiujê wartoœæ
		}
        
    	ResourceManager& operator=(const ResourceManager& i)  //kopiuj¹cy operator przypisania
    	{
    		*cos = *i.cos;
    		return *this;  //gdy korzystamy z operatora przypisania korzystamy z return 
		}
		
		ResourceManager(ResourceManager&& i)  //konstruktor przenosz¹cy
		{
			cos = (i.cos);
			i.cos = nullptr;  //nullptr to wskaŸnik pusty
		}
		
		ResourceManager& operator=(ResourceManager&& i)  //przenosz¹cy operator przypisania
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
