#include "stdafx.h"
#include "main_window.h"

class config_object_notify_columns : public config_object_notify
{
    unsigned get_watched_object_count() override
    {
        return 1;
    }
    GUID get_watched_object(unsigned p_index) override
    {
        return standard_config_objects::bool_ui_always_on_top;
    };
    void on_watched_object_changed(const service_ptr_t<config_object> & p_object) override
    {
        if (g_main_window)
        {
            bool aot = false;
            p_object->get_data_bool(aot);
            uPostMessage(g_main_window,MSG_SET_AOT,aot,0);
        }
    }

};

/*class titleformat_config_callback_columns : public titleformat_config_callback
{
    virtual void on_change(const GUID & p_guid,const char * p_name,const char * p_value,unsigned p_value_length)
    {
        if (g_main_window)
        {
            if (p_guid == titleformat_config::config_windowtitle)
                uPostMessage(g_main_window,MSG_UPDATE_TITLE,0,0);
            else if (p_guid == titleformat_config::config_statusbar)
                uPostMessage(g_main_window,MSG_UPDATE_STATUS,0,0);
        }
    }

};*/

service_factory_single_t<config_object_notify_columns> hj;
//service_factory_single_t<titleformat_config_callback_columns> hjc;
