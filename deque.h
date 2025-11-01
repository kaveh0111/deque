//problems with this code 
// 1-Const-correctness leaks mutability.
// 2-Weird/ambiguous push overload set.
//3 -

template <typename T>
struct Controller{
    
    static constexpr std::size_t m_block_size;
    std::size_t m_capacity;
    std::size_t num_ctr_block;
    T* m_head;
    T* m_tail;
    
};


template <typename T>
class deque{
    public:
    
    void insert(const T* position, const T* start_pos , const T* end_pos);
    void insert(const T* position, std::size_t num_copy, T value);
    void push_back(T* data);
    void push_back(T& data);
    void push_back(T data);
    void push_back(T&& data);
    
    void push_front(T* data);
    void push_front(T& data);
    void push_front(T data);
    void push_front(T&& data);
    
    void pop_back();
    void pop_front();
    
    T& operator[](std::size_t index) const;
    T& at(std::size_t index) const;
    T& operator()(std::size_t index) const;
    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    T& front() const noexcept;
    T& back() const noexcept;
    T* begin()const noexcept;
    T* end() const noexcept;
    bool empty() const noexcpet;
    void shrink_to_fit() noexcept;
    void clear() noexcept;
    void emplace(std::size_t index);
    void emplace_back(T );
    void swap(deque& other);
    T* erase(const T* index);
    T* erase(const T* first, const T* last);
    
    private:
    Controller<T> m_ctr_block;
    
    
    
};
