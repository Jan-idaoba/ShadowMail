#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


// how to ues 
//SmtpLib::Init();  // init libcurl
//
//SmtpConfig cfg = {/* server, port, username, password, useSSL */ };
//MimeMessage msg = {/* from, to, subject, body, attachments */ };
//
//auto client = std::make_unique<SmtpClient>(cfg);
//client->SendEmail(msg);
//
//SmtpLib::Cleanup(); // clean curl and so on.
//
