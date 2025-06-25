#pragma once
#include <string>
#include <vector>

struct AddressInfo 
{
	std::string strEmail;
	std::string strName;
};

class CMimeMessage
{
public:
	CMimeMessage();
	~CMimeMessage();

public:
	int Reset();

public:
	int AddRecipient(const char* pRecipient, const char* pName = nullptr);
	int GetRecipientsCount() const;
	const char* GetRecipientByIndex(unsigned int nIndex, unsigned int NameIndex = 0/*0 is the original name 1 is the alias*/) const;
	int ClearAllRecipients();

	int AddCc(const char* pCc, const char* pName = nullptr);
	int GetCcsCount() const;
	const char* GetCcByIndex(unsigned int nIndex, unsigned int NameIndex = 0/*0 is the original name 1 is the alias*/) const;
	int ClearAllCcs();

	int AddBcc(const char* pBcc, const char* pName = nullptr);
	int GetBccsCount() const;
	const char* GetBccByIndex(unsigned int nIndex, unsigned int NameIndex = 0/*0 is the original name 1 is the alias*/) const;
	int ClearAllBccs();

	int AddAttachment(const char* pAttachment);
	int GetAttachmentsCount() const;
	const char* GetAttachmentByIndex(unsigned int nIndex) const;
	int ClearAllAttachments();

	int AddLinkedResource(const char* pResourcePath, const char* pContantID);
	int GetLinkedResourcesCount() const;
	const char* GetLinkedResourceFileNameByIndex(unsigned int nIndex) const;
	const char* GetLinkedResourceContantIDByIndex(unsigned int nIndex) const;
	int ClearAllLinkedResources();

	int SetSender(const char* pSender, const char* pName = nullptr);
	const char* GetSenderByIndex(unsigned int nIndex = 0/*0 is the original name 1 is the alias*/) const;
	void ClearSender();

	void SetBodyFormat(bool bHTML = false);
	bool GetBodyFormat() const;

	void SetPriority(int nPriority = 0);
	int GetPriority() const;

	void SetSubject(const char* pSubject);
	const char* GetSubject()	const;

	void SetMessageBody(const char* pBody, int iIndex = 0);
	void SetMessageBodyFromFile(const char* pFileName, int iType = 0);
	const char* GetMessageBody(int iIndex = 0)	const;

private:
	bool										m_bhtml;
	int											m_iPriority;
	std::string									m_wstrSubject;
	std::string									m_wstrHTMLBody;
	std::string									m_wstrPlainTextBody;
	AddressInfo									m_tupSender;
	std::vector<AddressInfo>					m_vecRecipients;
	std::vector<AddressInfo>					m_vecCCs;
	std::vector<AddressInfo>					m_vecBccs;
	std::vector<std::string>					m_vecAttachments;
	std::vector<AddressInfo>					m_vecResources;
};
