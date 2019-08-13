# XML Documentation Style
In order to keep our XML doc comments self-consistent, please use the following guidelines and nomenclature throughout. Docs can be found here: https://docs.microsoft.com/en-us/cpp/ide/xml-documentation-visual-cpp.

## General
- Everything needs a `<summary>` tag.
- All methods must have a complete set of `<param>` and `<returns>` tags.
- Method summaries should describe what they do in the present tense. E.g. "Gets the number of widgets in a fob."
- Parameters should be in `<paramref>` blocks within summary/remarks tags. `<paramref>` is apparently not fully supported for C++, but such blocks will be highlighted by doxygen and still provide value in the plaintext header for denoting which blocks are parameters.
- Dangling prepositions are apparently ok, because that is what they are for.
- Not all items need to be described using the same voice. Apparently this is ok.
- `<seealso>` should be used:
    - To link related methods.
    - To link classes to their factory methods (if exposed from a different class).
    - TODO: other cases...
- `<seealso>` should NOT be used to reference the types of parameters or fields, since this information in inherent in the declarations (and so the doc generator can generate the links itself).
- `<summary>` vs. `<remarks>`
    - `<summary>` is the short one or two sentence description. In documentation, this is the text that is available without "drilling in". This is the the only source of descriptive data for Intellisense. For verbosely named types, this string may not provide much additional detail.
    - `<remarks>` are for all the other details. A user will need to intentionally click through to get this data.
- Strict adherence to line lengths can be ignored while we iterate on the documentation. As we near doc completion, we can do a clean-up pass.

## Party-specific
- Each state change must reference its related struct via `<seealso>`.
- Each state change struct must reference the related `PartyStateChangeType` and the method(s) which can generate it. For state changes that don't include full information (e.g. `PartyDestinationNetworkChangedStateChange`), a reference must be included to the API which retreives the additional information (e.g. `PartyNetwork::DestinationNetwork`).
- Each API which generates a state change must reference the state change struct.
- The ordering of related state changes must be documented on the state change struct (e.g. EndpointDestroyed is generated before DestroyEndpointCompleted).

## Consistency Decisions
- All comments should end in a period.
- Method names should include a trailing ().
- State changes are "returned to PartyManager::FinishProcessingStateChanges()".
- APIs "generate" state changes.
- The code calling our APIs is "the app".
- In a completed state change:
    - The original inputs should be referenced as follows: "The XXX provided to the call associated with this state change."
    - The object on which the API was called should be referenced as follows: "The XXX used in the call associated with this state change."
- When a pointer appears in a struct or parameter, it's doc comment should omit the word "pointer" and simply refer to the data directly. E.g. `PartyDataBuffer *` would be referred to as "data" rather than "pointer to data".
- When describing an object in a `<summary>`, use English rather than the type name. E.g. "The chat control where the properties changed." rather than "The PartyChatControl where the properties changed."
- When describing what is returned to `PartyManager::FinishProcessingStateChanges`, use the state change struct rather than enum value.
    - TODO: This breaks down for receipts, since multiple state changes use the same struct... reconsider.
- When describing the lifetime of data returned by PartyManager, use the word "valid" in phrases like "valid until", "becomes invalid when", etc.
- To describe the lifetime of something that becomes invalid when FinishProcessingStateChanges() is called, use one of the following:
    - For data buffers: The memory pointed to by `<c>XXX</c>` is only valid until XXX is returned to `PartyManager::FinishProcessingStateChanges()`.
    - For objects: The XXX `<c>XXX</c>` is only valid until XXX is returned to `PartyManager::FinishProcessingStateChanges()`.

## Open questions
- "Indicates why" vs. "Indicates the reason"
- Should lifetime remarks (e.g. a PartyLocalUser pointer in a PartyLocalUserDestroyed state change) be on the structs, the fields, or both?
- Should the async model be documented on every async method? Probably just referenced briefly.
    - Should each async method explicitly state that a successful return guarantees a `_completed` state change, and that a failure won't generate one? Should we just say that the method generates a `_completed` state change and explain in detail elsewhere that this is only for success?
    - See `PartyLocalDevice::CreateChatControl` for a possible treatment.
- When referring to more than one item, should we refer to them as a list, set, array, etc.?
