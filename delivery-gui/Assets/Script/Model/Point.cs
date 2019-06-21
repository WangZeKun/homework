//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 4.0.0
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class Point : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Point(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Point obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Point() {
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
          delivery_modelPINVOKE.delete_Point(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int x {
    set {
      delivery_modelPINVOKE.Point_x_set(swigCPtr, value);
    } 
    get {
      int ret = delivery_modelPINVOKE.Point_x_get(swigCPtr);
      return ret;
    } 
  }

  public int y {
    set {
      delivery_modelPINVOKE.Point_y_set(swigCPtr, value);
    } 
    get {
      int ret = delivery_modelPINVOKE.Point_y_get(swigCPtr);
      return ret;
    } 
  }

  public PointType type {
    set {
      delivery_modelPINVOKE.Point_type_set(swigCPtr, (int)value);
    } 
    get {
      PointType ret = (PointType)delivery_modelPINVOKE.Point_type_get(swigCPtr);
      return ret;
    } 
  }

  public uint order_id {
    set {
      delivery_modelPINVOKE.Point_order_id_set(swigCPtr, value);
    } 
    get {
      uint ret = delivery_modelPINVOKE.Point_order_id_get(swigCPtr);
      return ret;
    } 
  }

  public Point() : this(delivery_modelPINVOKE.new_Point__SWIG_0(), true) {
  }

  public Point(int x, int y) : this(delivery_modelPINVOKE.new_Point__SWIG_1(x, y), true) {
  }

  public Point(int x, int y, PointType type, uint order_id) : this(delivery_modelPINVOKE.new_Point__SWIG_2(x, y, (int)type, order_id), true) {
  }

  public static int GetDistant(Point from, Point to) {
    int ret = delivery_modelPINVOKE.Point_GetDistant(Point.getCPtr(from), Point.getCPtr(to));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static bool IsArrive(Point from, Point to) {
    bool ret = delivery_modelPINVOKE.Point_IsArrive(Point.getCPtr(from), Point.getCPtr(to));
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public static Point Move(Point from, Point to) {
    Point ret = new Point(delivery_modelPINVOKE.Point_Move(Point.getCPtr(from), Point.getCPtr(to)), true);
    if (delivery_modelPINVOKE.SWIGPendingException.Pending) throw delivery_modelPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}
