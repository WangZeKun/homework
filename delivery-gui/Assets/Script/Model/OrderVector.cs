//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 4.0.0
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class OrderVector : global::System.IDisposable, global::System.Collections.IEnumerable, global::System.Collections.Generic.IEnumerable<Order>
 {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal OrderVector(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(OrderVector obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~OrderVector() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          delivery_modelPINVOKE.delete_OrderVector(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public OrderVector(global::System.Collections.IEnumerable c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (Order element in c) {
      this.Add(element);
    }
  }

  public OrderVector(global::System.Collections.Generic.IEnumerable<Order> c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (Order element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public Order this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < size())
        throw new global::System.ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

  public void CopyTo(Order[] array)
  {
    CopyTo(0, array, 0, this.Count);
  }

  public void CopyTo(Order[] array, int arrayIndex)
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

  public void CopyTo(int index, Order[] array, int arrayIndex, int count)
  {
    if (array == null)
      throw new global::System.ArgumentNullException("array");
    if (index < 0)
      throw new global::System.ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new global::System.ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new global::System.ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new global::System.ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new global::System.ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

  public Order[] ToArray() {
    Order[] array = new Order[this.Count];
    this.CopyTo(array);
    return array;
  }

  global::System.Collections.Generic.IEnumerator<Order> global::System.Collections.Generic.IEnumerable<Order>.GetEnumerator() {
    return new OrderVectorEnumerator(this);
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator() {
    return new OrderVectorEnumerator(this);
  }

  public OrderVectorEnumerator GetEnumerator() {
    return new OrderVectorEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class OrderVectorEnumerator : global::System.Collections.IEnumerator
    , global::System.Collections.Generic.IEnumerator<Order>
  {
    private OrderVector collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public OrderVectorEnumerator(OrderVector collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public Order Current {
      get {
        if (currentIndex == -1)
          throw new global::System.InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new global::System.InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new global::System.InvalidOperationException("Collection modified.");
        return (Order)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object global::System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new global::System.InvalidOperationException("Collection modified.");
      }
    }

    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
  }

  public void Clear() {
    delivery_modelPINVOKE.OrderVector_Clear(swigCPtr);
  }

  public void Add(Order x) {
    delivery_modelPINVOKE.OrderVector_Add(swigCPtr, Order.getCPtr(x));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  private uint size() {
    uint ret = delivery_modelPINVOKE.OrderVector_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = delivery_modelPINVOKE.OrderVector_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    delivery_modelPINVOKE.OrderVector_reserve(swigCPtr, n);
  }

  public OrderVector() : this(delivery_modelPINVOKE.new_OrderVector__SWIG_0(), true) {
  }

  public OrderVector(OrderVector other) : this(delivery_modelPINVOKE.new_OrderVector__SWIG_1(OrderVector.getCPtr(other)), true) {
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public OrderVector(int capacity) : this(delivery_modelPINVOKE.new_OrderVector__SWIG_2(capacity), true) {
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  private Order getitemcopy(int index) {
    Order ret = new Order(delivery_modelPINVOKE.OrderVector_getitemcopy(swigCPtr, index), true);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private Order getitem(int index) {
    Order ret = new Order(delivery_modelPINVOKE.OrderVector_getitem(swigCPtr, index), false);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, Order val) {
    delivery_modelPINVOKE.OrderVector_setitem(swigCPtr, index, Order.getCPtr(val));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(OrderVector values) {
    delivery_modelPINVOKE.OrderVector_AddRange(swigCPtr, OrderVector.getCPtr(values));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public OrderVector GetRange(int index, int count) {
    global::System.IntPtr cPtr = delivery_modelPINVOKE.OrderVector_GetRange(swigCPtr, index, count);
    OrderVector ret = (cPtr == global::System.IntPtr.Zero) ? null : new OrderVector(cPtr, true);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, Order x) {
    delivery_modelPINVOKE.OrderVector_Insert(swigCPtr, index, Order.getCPtr(x));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, OrderVector values) {
    delivery_modelPINVOKE.OrderVector_InsertRange(swigCPtr, index, OrderVector.getCPtr(values));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    delivery_modelPINVOKE.OrderVector_RemoveAt(swigCPtr, index);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    delivery_modelPINVOKE.OrderVector_RemoveRange(swigCPtr, index, count);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public static OrderVector Repeat(Order value, int count) {
    global::System.IntPtr cPtr = delivery_modelPINVOKE.OrderVector_Repeat(Order.getCPtr(value), count);
    OrderVector ret = (cPtr == global::System.IntPtr.Zero) ? null : new OrderVector(cPtr, true);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    delivery_modelPINVOKE.OrderVector_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    delivery_modelPINVOKE.OrderVector_Reverse__SWIG_1(swigCPtr, index, count);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, OrderVector values) {
    delivery_modelPINVOKE.OrderVector_SetRange(swigCPtr, index, OrderVector.getCPtr(values));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
  }

}
