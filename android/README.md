# Android
Please download, unzip, and copy the android library binaries to: `/bin/release`.

## Troubleshooting
### JNIEnv
If you experience a crash similar to this during runtime:
```
F/DEBUG   : signal 11 (SIGSEGV), code 1 (SEGV_MAPERR), fault addr 0x0
F/DEBUG   : Cause: null pointer dereference
F/DEBUG   : backtrace:
F/DEBUG   : #00 pc 000000000026b574  <Project path>==/lib/arm64/libparty.so (_ZN19BumblelionJniHelper16CreateUUIDStringERA37_c+64) (BuildId: e61de1c7e18214f867af00b8df6ffab2091b55c0)
F/DEBUG   : #01 pc 0000000000261df4  <Project path>==/lib/arm64/libparty.so (BumblelionCreateUuid(BumblelionUuid&)+100)   (BuildId: e61de1c7e18214f867af00b8df6ffab2091b55c0)
F/DEBUG   : #02 pc 00000000001fc158  <Project path>==/lib/arm64/libparty.so (BumblelionImpl::Initialize(char const*)+116)   (BuildId: e61de1c7e18214f867af00b8df6ffab2091b55c0)
F/DEBUG   : #03 pc 00000000001fbf38  <Project path>==/lib/arm64/libparty.so (BumblelionImpl::Create(char const*,   BumblelionImpl**)+232) (BuildId: e61de1c7e18214f867af00b8df6ffab2091b55c0)
F/DEBUG   : #04 pc 00000000001facd8  <Project path>==/lib/arm64/libparty.so (PartyInitialize+128) (BuildId:   e61de1c7e18214f867af00b8df6ffab2091b55c0)
```
Ensure you are calling `System.loadLibrary()` on the library as this is what passes the `JNIEnv` pointer to `libparty.so`.
See `PartySample/demo/src/main/cpp/CMakeLists.txt` on how to setup the library as an imported target.

### Gradle
Ensure you have added the `.aar` file(s) to your project and all the required `build.gradle` dependencies:
```
implementation fileTree(dir: 'libs', include: ['*.aar'])
implementation 'com.squareup.okhttp3:okhttp:4.9.1'
implementation 'com.google.code.gson:gson:2.8.5'
implementation 'com.playfab:client-sdk:0.82.181218'
```
See [quickstart android docs](https://learn.microsoft.com/en-us/gaming/playfab/sdks/c/quickstart-android) and `PartySample/demo/build.gradle` for more info.

### Proguard
Proguard might try to optimise code which may result in required symbols being stripped away. Add these rules to proguard to prevent this:
```
-keep class com.bumblelion.** { *; }
-keep class com.microsoft.** { *; }
```
Proguard may also produce warnings on some of our dependencies, these extra rules can be added to suppress them - see [okhttp commit](https://github.com/square/okhttp/commit/9da841c24c3b3dabc1d9230ab2f1e71105768771).
```
-dontwarn okhttp3.internal.platform.**
-dontwarn org.conscrypt.**
-dontwarn org.bouncycastle.**
-dontwarn org.openjsse.**
```
