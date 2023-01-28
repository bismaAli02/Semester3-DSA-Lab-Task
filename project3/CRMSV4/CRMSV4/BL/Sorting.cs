using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CRMSV4.BL;

namespace CRMSV4.BL
{
    public  class Sorting
    {

        private static void Swap<T>(List<T> list, int i, int j)
        {
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
        ////////////// Bubble Sort

        public static void BubbleSort(List<Customer> Customers)
        {
            for (int x = 0; x < Customers.Count() - 1; x++)
            {
                bool isSwapped = false;
                for (int y = 0; y < Customers.Count() - x - 1; y++)
                {
                    if (Int32.Parse(Customers[y].CustID) > Int32.Parse(Customers[y + 1].CustID))
                    {
                        //swap(Customers[y], Customers[y + 1]);
                        Swap<Customer>(Customers, y, y + 1);
                        isSwapped = true;
                    }
                }
                if (!isSwapped)
                {
                    break;
                }
            }
        }


        ////////////// Selection Sort
        private static int findMinimum(List<Customer> Customers, int start, int end)
        {
            int min = Int32.Parse(Customers[start].CustID);
            int minIndex = start;
            for (int x = start; x < end; x++)
            {
                if (min > Int32.Parse(Customers[x].CustID))
                {
                    min = Int32.Parse(Customers[x].CustID);
                    minIndex = x;
                }
            }
            return minIndex;
        }
        public static void selectionSort(List<Customer> Customers)
        {
            for (int x = 0; x < Customers.Count() - 1; x++)
            {
                int minIndex = findMinimum(Customers, x, Customers.Count());
                //swap(Customers[x], Customers[minIndex]);
                Swap<Customer>(Customers, x, minIndex);
            }
        }
        ////////////// Insertion Sort
        public static void insertionSort(List<Customer> Customers)
        {
            for (int x = 1; x < Customers.Count(); x++)
            {
                Customer key = Customers[x];
                int y = x - 1;
                while (y >= 0 && Int32.Parse(Customers[y].CustID) > Int32.Parse(key.CustID))
                {
                    Customers[y + 1] = Customers[y];
                    y--;
                }
                Customers[y + 1] = key;
            }
        }

        ////////////// Merge Sort

        private static void merge(List<Customer> Customers, int start, int mid, int end)
        {
            int i = start;
            int j = mid + 1;
            Queue<Customer> tempArr = new Queue<Customer>();
            while (i <= mid && j <= end)
            {
                if (Int32.Parse(Customers[i].CustID) < Int32.Parse(Customers[j].CustID))
                {
                    tempArr.Enqueue(Customers[i]);
                    i++;
                }
                else
                {
                    tempArr.Enqueue(Customers[j]);
                    j++;
                }
            }
            while (i <= mid)
            {
                tempArr.Enqueue(Customers[i]);
                i++;
            }
            while (j <= end)
            {
                tempArr.Enqueue(Customers[j]);
                j++;
            }
            for (int x = start; x <= end; x++)
            {
                Customers[x] = tempArr.Peek();
                tempArr.Dequeue();
            }
        }

        private static void mergeSort(List<Customer> Customers, int start, int end)
        {
            if (start < end)
            {
                int mid = (start + end) / 2;
                mergeSort(Customers, start, mid);
                mergeSort(Customers, mid + 1, end);
                merge(Customers, start, mid, end);
            }
        }

        public static void mergeSort(List<Customer> Customers)
        {
            mergeSort(Customers, 0, Customers.Count() - 1);
        }

        ////////////// Quick Sort

        private static int partition(List<Customer> Customers, int start, int end, int pivot)
        {
            int left = start;
            int right = end;
            while (left <= right)
            {
                while (Int32.Parse(Customers[left].CustID) < Int32.Parse(Customers[pivot].CustID) && left <= end)
                    left++;
                while (Int32.Parse(Customers[right].CustID) >= Int32.Parse(Customers[pivot].CustID) && right >= start)
                    right--;
                if (left < right)
                    Swap<Customer>(Customers, left, right);
                //swap(Customers[left], Customers[right]);
            }
            // swap(Customers[right], Customers[pivot]);
            Swap<Customer>(Customers, right, pivot);
            return right;
        }
        private static void quickSort(List<Customer> Customers, int start, int end)
        {
            if (start < end)
            {
                int pivot = start;
                int mid = partition(Customers, start + 1, end, pivot);
                quickSort(Customers, start, mid - 1);
                quickSort(Customers, mid + 1, end);
            }
        }
        public static void quickSort(List<Customer> Customers)
        {
            quickSort(Customers, 0, Customers.Count() - 1);
        }

        ////////////// Heap Sort

        private static int parentIndex(int i)
        {
            return (i - 1) / 2;
        }
        private static int leftChildIndex(int i)
        {
            return (2 * i) + 1;
        }
        private static int rightChildIndex(int i)
        {
            return (2 * i) + 2;
        }

        private static void heapify(List<Customer> Customers, int size, int index)
        {
            int maxIndex;
            while (true)
            {
                int lIdx = leftChildIndex(index);
                int rIdx = rightChildIndex(index);
                if (rIdx >= size)
                {
                    if (lIdx >= size)
                        return;
                    else
                        maxIndex = lIdx;
                }
                else
                {
                    if (Int32.Parse(Customers[lIdx].CustID) >= Int32.Parse(Customers[rIdx].CustID))
                        maxIndex = lIdx;
                    else
                        maxIndex = rIdx;
                }
                if (Int32.Parse(Customers[index].CustID) < Int32.Parse(Customers[maxIndex].CustID))
                {
                    //swap(Customers[index], Customers[maxIndex]);
                    Swap<Customer>(Customers, index,maxIndex);
                    index = maxIndex;
                }
                else
                    return;
            }
        }

        public static void heapSort(List<Customer> Customers)
        {
            for (int x = (Customers.Count() / 2) - 1; x >= 0; x--)
            {
                heapify(Customers, Customers.Count(), x);
            }
            for (int x = Customers.Count() - 1; x > 0; x--)
            {
                // swap(Customers[0], Customers[x]);
                Swap<Customer>(Customers, 0,x);
                heapify(Customers, x, 0);
            }
        }

        // Counting Sort
        private static int FindMaximum(List<Customer> Customers)
        {
            int maxVal = Int32.Parse(Customers[0].CustID);
            for(int i=0;i<Customers.Count;i++)
            {
                if (maxVal < Int32.Parse(Customers[i].CustID))
                {
                    maxVal = Int32.Parse(Customers[i].CustID);
                }
            }

            return maxVal;
        }
        public static void countingSort(List<Customer> Customers )
        {
            int max = FindMaximum(Customers);
            int[] count = new int[max+1];
            Customer[] output= new Customer[Customers.Count];
            for (int x = 0; x < Customers.Count; x++)
            {
                count[Int32.Parse(Customers[x].CustID)]++;
            }
            for (int x = 1; x < count.Length; x++)
            {
                count[x] = count[x - 1] + count[x];
            }
            for (int x = Customers.Count - 1; x >= 0; x--)
            {
                int index = count[Int32.Parse(Customers[x].CustID)] - 1;
                count[Int32.Parse(Customers[x].CustID)]--;
                output[index] = Customers[x];
            }
            for (int x = 0; x < output.Length; x++)
            {
                Customers[x] = output[x];
            }
        }

        // Radix Sort
        private static void countingSort(List<Customer> Customers,int place)
        {
            int max = FindMaximum(Customers);
            int[] count = new int[10];
            Customer[] output = new Customer[Customers.Count];
            for (int x = 0; x < Customers.Count; x++)
            {
                count[(Int32.Parse(Customers[x].CustID)/place)%10]++;
            }
            for (int x = 1; x < count.Length; x++)
            {
                count[x] = count[x - 1] + count[x];
            }
            for (int x = Customers.Count - 1; x >= 0; x--)
            {
                int index = count[(Int32.Parse(Customers[x].CustID) / place) % 10] - 1;
                count[(Int32.Parse(Customers[x].CustID) / place) % 10]--;
                output[index] = Customers[x];
            }
            for (int x = 0; x < output.Length; x++)
            {
                Customers[x] = output[x];
            }
        }
        public static void radixSort(List<Customer> Customers)
        {
            int max = FindMaximum(Customers);
            int place = 1;
            while ((max / place) > 0)
            {
                countingSort(Customers, place);
                place = place * 10;
            }
        }
        // Bucket Sort
        public static void bucketSort(List<Customer> Customers)
        {
            List<List<Customer>> bucket = new List<List<Customer>>();

            for (int x = 0; x < Customers.Count(); x++)
            {
                bucket.Add(new List<Customer>());
            }

            for (int x = 0; x < Customers.Count; x++)
            {
                bucket[(Int32.Parse(Customers[x].CustID) * Customers.Count) % Customers.Count].Add(Customers[x]);
            }
            for (int x = 0; x < bucket.Count; x++)
            {
                insertionSort(bucket[x]);
            }
            int index = 0;
            for (int x = 0; x < bucket.Count; x++)
            {
                for (int y = 0; y < bucket[x].Count; y++)
                {
                    Customers[index] = bucket[x][y];
                    index++;
                }
            }
        }
    }
}
