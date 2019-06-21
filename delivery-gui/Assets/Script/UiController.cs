using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UiController : MonoBehaviour
{
    //绑定退出按钮
    public void on_button_click()
    {
        Debug.Log("exit");
        Application.Quit();
    }
}
