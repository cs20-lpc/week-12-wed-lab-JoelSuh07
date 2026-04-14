template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int i = 0;
    while (i < M) {
        int index = probeIndex(key, i);
        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            N++;
            return i + 1; // return number of probe
        }
        i++;
    }
    return i; //if table is full, return i
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int i = 0;
    while (i < M) {
        int index = probeIndex(key, i);

        if (!occupied[index]) { // if slot is empty, the key doesn't exist
            return {false, i + 1};
        }

        if (table[index] == key) { // if the slot is occupied check if it is the key
            return {true, i + 1};
        }

        i++;
    }

    return {false, i}; // table is full and key not found
}
