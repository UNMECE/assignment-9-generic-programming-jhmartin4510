#include <iostream>

template <typename T>
class p_vector			//p_vector (pseudo vector)
{
	private:
		T *value;
		int size;

	public:
//default constructor
		p_vector()
		{
			size = 0;
			value = NULL;
		}
//add element
		void addElement(T input)
		{
			if(size == 0)
			{
				value = new T;		
				*value  = input;
				size++;
				return;
			}
			T *temp = new T[size+1];
			for(int i = 0; i<size; i++)
			{
				temp[i] = value[i]; 
			}
			temp[size] = input;
			delete[] value;
			value = temp;
			size++;
		}
//.at function. return value in the array at the location parameter	
		T at(int location)
		{
			return value[location]; 	
		}
//size function
		int Size()
		{
			return size;
		}
//sum function
		T sum()
		{
			T sum=0;
			for(int i =0; i<size; i++)
			{
				sum += value[i];
			}
			return sum;	
		}
//max function
		T max()
		{
			T max = *value;
			for(int i = 0; i<size; i++)
			{
				if(value[i]>max)
				{
					max = value[i];
				}
			}
			return max;
		}
//min function
		T min()
		{
			T min = *value;
			for(int i = 0; i<size; i++)
			{
				if(value[i]<min)
				{
					min = value[i];
				}
			}
			return min;
		}
//slice function
		T* slice(int begin, int end)
		{
			if(begin >0 && end<=size)
			{
				T* temp = new T[end-begin+1];
				for(int i = 0, j = begin;i<(end-begin+1);i++,j++)
				{
					temp[i]=value[j]; 
				}
				return temp;
			}
			std::cout<<"This is not a valid slice" <<std::endl;
			return 0;
		}
//print function
		void print()
		{
			std::cout<<"Printing all elements in this array" <<std::endl;
			std::cout<<"-----------------------------------" <<std::endl;
			for(int i =0; i<size; i++)
			{
				std::cout<<value[i] <<" ";
			}	
			std::cout<<std::endl <<"-----------------------------------"<<std::endl;
		}
//destructor
		~p_vector()
		{
			delete[] value;
		}		
};


int main()
{
	p_vector <int> arr;
	arr.addElement(10);
	arr.addElement(20);
	arr.addElement(40);
	arr.addElement(20);
	arr.addElement(90);
	arr.addElement(3);
	arr.addElement(10);
	
	std::cout<<"Size of array is: " <<arr.Size() <<std::endl;
	std::cout<<"Sum of the array is: " <<arr.sum() <<std::endl;
	std::cout<<"Max is: " <<arr.max() <<std::endl;
	std::cout<<"Min is: " <<arr.min() <<std::endl;
 	arr.print();
	
	int* slice = arr.slice(2,4);
	int length = 4-2+1;
	std::cout<<"Printing the array slice" <<std::endl;
	std::cout<<"------------------------" <<std::endl;
	for(int i =0; i<length;i++)
	{
		std::cout<<slice[i] <<" ";
	}
	std::cout<<std::endl <<"------------------" <<std::endl;


delete[] slice;
return 0;
}
