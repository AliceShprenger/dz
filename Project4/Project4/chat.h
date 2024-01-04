#pragma once
#include "sha1.h"
#include "string.h"
#define SIZE 10
#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
    bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);

private:
    enum enPairStatus {
        free, // свободен
        engaged, //занят
        deleted //удален
    };
    struct AuthData {
        AuthData() :
            login(""),
            pass_sha1_hash(0), status(enPairStatus::free) {
        }
        ~AuthData() {
            if (pass_sha1_hash != 0)
                delete[] pass_sha1_hash;
        }
        AuthData(char _login[LOGINLENGTH], uint* sh1) {
            strcpy_s(login, _login);
            pass_sha1_hash = sh1;
            status = enPairStatus::engaged;
        }
        AuthData& operator = (const AuthData& other) {
            strcpy_s(login, other.login);
            status = other.status;
            if (pass_sha1_hash != 0)
                delete[] pass_sha1_hash;
            pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];

            memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);

            return *this;
        }
        char login[LOGINLENGTH];
        uint* pass_sha1_hash;
        enPairStatus status;
    };
    int hfunc(int val);
    int hash_func(char* fr_name, int offset);
    AuthData data[SIZE];
    int data_count;
};