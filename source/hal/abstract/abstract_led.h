
class AbstractLed {
  public:
    virtual void turnOff() = 0;
    virtual void turnOn() = 0;
    virtual void toggle() = 0;
    virtual bool isOn() = 0;
};