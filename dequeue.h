#include <utility>
#include <vector>

constexpr std::size_t   NUM_BLOCKS = 2;
constexpr std::size_t   BLOCK_SIZE_NUM = 20;
constexpr std::size_t   BLOCK_SIZE_BYTE = 120;

//use reinterpret_cast and reserving raw bit to prevent default constructor destructor calling 
//consider to change naming to map and buffer.
//increasing the size when the controller and the buffer it is full
//shrink to fit and decreasing the size
//size indication 

template <typename T>
struct Controller{
    Controller() noexcept;
    ~Controller() noexcept;
    Controller(const Controller& other) = delete;
    Controller(Controller&& other) noexcept;
    Controller& operator=(const Controller& other) = delete;
    Controller& operator=(Controller&& other) noexcept;
    
    //it is better to make this a function where there are variable size for class
    std::size_t m_block_size = std::min(20 * sizeof(T), static_cast<std::size_t>(BLOCK_SIZE_BYTE / sizeof(T)));
    std::size_t m_num_blocks = BLOCK_SIZE_BYTE;
    std::vector<T*> m_block; //should be filled with nullptr? //it is a pointer to the map
    T* m_mid_block;
    T* m_tail_block;
    T* m_head_block;
    //index to memory formulas
    
};





template <typename T>
class dequeue{
    public:
    dequeue();
    explicit dequeue(std::size_t size);
    explicit dequeue(std::size_t size, const T& value);
    dequeue(T* start_ptr, T* end_ptr);
    ~dequeue() noexcept;
    dequeue(const dequeue& other) = delete;
    dequeue(dequeue&& other) noexcept;
    dequeue& operator=(const dequeue& other) = delete;
    dequeue& operator=(dequeue&& other) noexcept;
    void push_back();
    void push_front();
    void emplace_back();
    void emplace_front();
    void pop_front();
    void pop_back();
    T& front();
    T& back();
    T* begin();
    T* end();
    T& operator*();
    T* operator->();
    T& operator[](std::size_t position);
    T& at(std::size_t position);
    
    const T& front() const;
    const T& back() const;
    const T* begin() const;
    const T* end() const;
    const T& operator*() const;
    const T* operator->() const;
    const T& operator[](std::size_t position) const;
    const T& at(std::size_t position) const;
    
    const T& cfront() const;
    const T& cback() const;
    const T* cbegin() const;
    const T* cend() const;
    T& cfront();
    T& cback();
    T* cbegin();
    T* cend();
    
    void clear() noexcept;
    bool empty() const noexcept;
    bool full() const noexcept;
    std::size_t size() const noexcept;
    
    const T* insert(std::size_t position);
    T* insert(const T* insert_position, const T* start, const T* end);
    void shrink_to_fit() noexcept;
    T* erase(T* position);
    T* erase(T* start_pos, T* end_pos);
    void resize(std::size_t new_size) noexcept;
    
    void swap(dequeue& other) noexcept;
    
    
    private:
    Controller<T> m_ctrl_block = nullptr;
    
    
};
