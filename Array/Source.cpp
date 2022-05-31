template <typename T>
struct ccA
{
    T* Array;
    void SetArray(T Digit, int counter)
    {
        Array[counter] = Digit;
    }
    ccA* next;
    ccA* prev;
};
template <typename T>
class clash_container_Array
{
    ccA<T>* Head;
    ccA<T>* Tail;
    int size = 0;
    int counter = 0;
public:
    clash_container_Array(int s_size = 10) : Head(nullptr), Tail(nullptr)
    {
        SetSize(s_size, 0);
    }

    void AddToHead(int Digit)
    {
        if (counter == size)
        {
            cout << "\n\tArray is full!\n\tChange Size Array!\n";
            return;
        }

        if (Head == nullptr && Tail == nullptr)
        {
            Head = new ccA<T>;
            Tail = Head;
            Head->SetArray(Digit, counter);
            Head->next = nullptr;
            Head->prev = nullptr;
        }
        else
        {
            ccA<T>* O = new ccA<T>;
            O->SetArray(Digit, counter);
            O->next = Head;
            O->prev = nullptr;
            Head->prev = O;
            Head = O;
        }
        ++counter;
    }
    void Fill_Array()
    {
        cout << "\nWe have: " << size + 1 << " free cell.\n";
        for (int i = 0; i < size; ++i)
        {
            cout << "Enter " << i + 1 << " cell: " << Head->Array[i] << endl;
            AddToHead(Head->Array[i]);
        }
    }
    int GetSize()
    {
        return size;
    }

    void SetSize(int s_size, int grow = 1)
    {
        if (s_size + grow > GetSize())
            size = s_size + grow;
        else
            size = s_size;
    }



};