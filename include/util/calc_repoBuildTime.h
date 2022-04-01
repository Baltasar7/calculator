#ifndef D_calc_repoBuildTime_H
#define D_calc_repoBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  calc_repoBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class calc_repoBuildTime
  {
  public:
    explicit calc_repoBuildTime();
    virtual ~calc_repoBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    calc_repoBuildTime(const calc_repoBuildTime&);
    calc_repoBuildTime& operator=(const calc_repoBuildTime&);

  };

#endif  // D_calc_repoBuildTime_H
