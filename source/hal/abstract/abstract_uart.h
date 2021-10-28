class AbstractUart {
  public:
    virtual void uartTx(char byte) = 0;
    virtual char uartRx() = 0;
};