#ifndef HTTP_KEYVALUE_SET
#define HTTP_KEYVALUE_SET
#include"byte_array/const_byte_array.hpp"

#include<map>
namespace fetch {
namespace http {

  
class KeyValueSet : private std::map< byte_array::ConstByteArray, byte_array::ConstByteArray >
{
public:
  typedef std::map< byte_array::ConstByteArray, byte_array::ConstByteArray > super_type;  
  typedef byte_array::ConstByteArray byte_array_type;
  typedef std::map< byte_array_type, byte_array_type > map_type;
  typedef map_type::iterator iterator;
  typedef map_type::const_iterator const_iterator;

  iterator begin() noexcept { return map_type::begin(); }
  iterator end() noexcept { return map_type::end(); }
  const_iterator begin() const noexcept { return map_type::begin(); }
  const_iterator end() const noexcept { return map_type::end(); }
  const_iterator cbegin() const noexcept { return map_type::cbegin(); }
  const_iterator cend() const noexcept { return map_type::cend(); }

  void Add(byte_array_type const& name, byte_array_type const &value) {    
    insert( {name, value} );
  }

  
  void Add(byte_array_type const& name, int const &n) {
    byte_array_type value( std::to_string(n) );
    insert( {name, value} );
  }
  
  bool Has(byte_array_type const& key) const {
    return this->find(key)  != this->end();
  }

  byte_array::ConstByteArray& operator[]( byte_array::ConstByteArray const &name) 
  {
    return super_type::operator[](name);    
  }

  byte_array::ConstByteArray const& operator[]( byte_array::ConstByteArray const &name)  const
  {
    return this->find(name)->second;    
  }
  

  
  void Clear() 
  {
    this->clear();
  }
  
private:

};

};
};

#endif