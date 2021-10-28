
class AbstractWatchdogTimer {
  public:
    virtual void start(uint32_t resetValue) = 0;
    virtual void feed() = 0;
};