// TODO: write function read_content: filesystem::path -> std::vector<char>

//#include <filesystem>
//#include <fstream>
//
//auto read_content(std::experimental::filesystem::path const & path) -> std::vector<char>
//{
//    if (!exists(path))
//        throw std::logic_error("no such file");
//
//    std::ifstream in(path.string(), std::ios::end);
//    std::vector<char> result(in.tellg());
//    in.seekg(std::ios::beg);
//    in.read(result.data(), result.size());
//    return result;
//}

// ----------------------------------------------------------------------------------------------------------------- //

struct Interface
{
    virtual ~Interface() = default;
};

struct KnownImplementation : Interface
{
    int field;
};

// TODO: write function get_int_ptr: std::shared_ptr<Interface> -> std::shared_ptr<int>

//std::shared_ptr<int> get_int_ptr(std::shared_ptr<Interface> i)
//{
//    if (auto known_implementation = std::dynamic_pointer_cast<KnownImplementation>(i))
//        return{ known_implementation, &known_implementation->field };
//    else
//        return std::make_shared<int>();
//}
