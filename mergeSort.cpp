#include <iostream>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <ctime>


using namespace std;

template<typename T>
void MergeSort(T a[], size_t l);

int main()
{
    cout << "Input size of array:";
    int sizeOfArray;
    cin >> sizeOfArray;

    cout << "Choose the method of filling:" << endl;
    cout << "1.Random filling" << endl;
    cout << "2.Hand filling" << endl;

    int choise;
    cin >> choise;

    int *arr = new int[sizeOfArray];

    switch (choise)
    {
    case 1:
        {
            cout << "Choose the module:";
            int module;
            cin >> module;

            for(auto i = 0; i < sizeOfArray; ++i)
                arr[i] = rand() % module;

            break;
        }


    case 2:
        {
            for(auto i = 0; i < sizeOfArray; ++i)
                cin >> arr[i];

            break;
        }

    default:
        break;
    }

    int action = 0;

    while(action != 3)
    {
        cout << "Choose action:" << endl;
        cout << "1.Sort array" << endl;
        cout << "2.Print array" << endl;
        cout << "3.Exit" << endl;

        cin >> action;

        switch(action)
        {
        case 1:
            {
                unsigned int time = clock();
                MergeSort(arr, sizeOfArray);
                time = -time + clock();
                cout << time << endl;
                break;
            }

        case 2:
            {
                for(auto i = 0; i < sizeOfArray; ++i)
                    cout << arr[i] << ",";

                break;
            }

        default:
            break;
        }
    }

    return 0;
}


template<typename T>
void MergeSort(T a[], size_t l)
{
	size_t BlockSizeIterator;
	size_t BlockIterator;
	size_t LeftBlockIterator;
	size_t RightBlockIterator;
	size_t MergeIterator;

	size_t LeftBorder;
	size_t MidBorder;
	size_t RightBorder;
	for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
	{
		for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
		{
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < l) ? RightBorder : l;
			int* SortedBlock = new int[RightBorder - LeftBorder];

			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
					RightBlockIterator += 1;
				}
			}

			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
				LeftBlockIterator += 1;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
				RightBlockIterator += 1;
			}

			for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
			{
				a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
			}
			delete SortedBlock;
		}
	}
}
