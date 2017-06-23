///////////////////////////////////////////////////////////////////////////// 
// Name:        imaggif.h 
// Purpose:     interface of wxGIFHandler 
// Author:      Samuel Dunn 
// Licence:     wxWindows licence 
//////////////////////////////////////////////////////////////////////////// 

#define wxIMAGE_OPTION_GIF_COMMENT wxT("GifComment")

/**
    @class wxGIFHandler

    This is the image handler for the GIF format.

    @library{core}
    @category{gdi}

    @see wxImage, wxImageHandler, wxInitAllImageHandlers()
*/
class wxGIFHandler : public wxImageHandler
{
public:
    /**
    Default constructor for wxGIFHandler
    */
    wxGIFHandler();

    virtual bool LoadFile(wxImage *image, wxInputStream& stream, bool verbose = true, 
                            int index = -1);
    virtual bool SaveFile(wxImage *image, wxOutputStream& stream, bool verbose=true);

    /**
        Save the animated gif.
        
        @param images
            The image array object which is to be affected by this operation.
        @param stream
            Opened output stream for writing the data.
        @param verbose
            If set to @true, errors reported by the image handler will produce wxLogMessages

        @return @true if the operation was successful, @false otherwise
    */
    bool SaveAnimation(const wxImageArray& images, wxOutputStream *stream,
                        bool verbose = true, int delayMilliSecs = 1000);

protected:
    virtual int DoGetImageCount(wxInputStream& stream);
    virtual bool DoCanRead(wxInputStream& stream);

    bool DoSaveFile(const wxImage&, wxOutputStream *, bool verbose,
        bool first, int delayMilliSecs, bool loop,
        const wxRGB *pal, int palCount,
        int mask_index);
};