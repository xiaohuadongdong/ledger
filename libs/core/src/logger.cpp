#include"core/logger.hpp"


namespace fetch {
  std::map< std::thread::id, int > fetch::log::ReadableThread::thread_number_ = std::map< std::thread::id, int > ();
  int fetch::log::ReadableThread::thread_count_ = 0;
  std::mutex fetch::log::ReadableThread::mutex_ ;
  
  log::details::LogWrapper logger;

  namespace log {
    Context::Context( void* instance) 
    {
      created_ =   std::chrono::high_resolution_clock::now();
      details_ = std::make_shared< ContextDetails >(instance);
      fetch::logger.SetContext( details_ );
    }
    
    
    Context::Context(shared_type ctx,  std::string const & context, std::string const & filename, int const &line, void* instance)
    {
      created_ =   std::chrono::high_resolution_clock::now();  
      details_ = std::make_shared< ContextDetails >(ctx, fetch::logger.TopContext(), context, filename, line, instance);
      fetch::logger.SetContext( details_ );  
    }
    
    Context::Context(std::string const & context , std::string const & filename, int const &line,  void* instance  ) 
    {
      created_ = std::chrono::high_resolution_clock::now();
      details_ = std::make_shared< ContextDetails >(fetch::logger.TopContext(), context, filename, line, instance);    
      fetch::logger.SetContext( details_ );
    }
    
    Context::~Context() 
    {
      std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
      double total_time =  double( std::chrono::duration_cast<std::chrono::milliseconds>(end_time - created_).count() );
      fetch::logger.UpdateContextTime( details_, total_time );
      
      if(primary_ && details_->parent() )
        {    
          fetch::logger.SetContext( details_->parent() );
        }
    }
  }
 
}