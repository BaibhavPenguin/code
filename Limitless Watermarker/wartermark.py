from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

# =========================
# Configuration
# =========================


OUTPUT_DIR = Path("watermarked")

WATERMARK_TEXT = "LIMITLESS"

# Opacity: 0 = invisible, 255 = fully opaque
WATERMARK_OPACITY = 70

# Grey value: 0 = black, 255 = white
WATERMARK_GREY = 128

# Relative font size based on image width
FONT_SIZE_RATIO = 6

# Rotation angle in degrees
ROTATION_ANGLE = 35

# Supported image formats
SUPPORTED_FORMATS = {
    ".jpg",
    ".jpeg",
    ".png",
    ".webp",
    ".bmp",
    ".tiff",
}


# =========================
# Font
# =========================

def get_font(size):
    """
    Try a few common fonts. Falls back to Pillow's default font.
    """
    font_paths = [
        "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf",
        "/usr/share/fonts/truetype/liberation2/LiberationSans-Bold.ttf",
        "C:/Windows/Fonts/arialbd.ttf",
        "C:/Windows/Fonts/calibrib.ttf",
    ]

    for path in font_paths:
        if Path(path).exists():
            return ImageFont.truetype(path, size)

    return ImageFont.load_default()


# =========================
# Watermark
# =========================

def add_watermark(image):
    """
    Add a diagonal, semi-transparent grey watermark
    across the center of the image.
    """

    image = image.convert("RGBA")

    width, height = image.size

    font_size = max(20, int(width * FONT_SIZE_RATIO))
    font = get_font(font_size)

    # Create a transparent layer
    watermark = Image.new(
        "RGBA",
        (width, height),
        (0, 0, 0, 0)
    )

    draw = ImageDraw.Draw(watermark)

    # Calculate text bounding box
    bbox = draw.textbbox(
        (0, 0),
        WATERMARK_TEXT,
        font=font
    )

    text_width = bbox[2] - bbox[0]
    text_height = bbox[3] - bbox[1]

    # Draw text slightly oversized so the rotated watermark
    # has enough room.
    draw.text(
        (
            (width - text_width) / 2,
            (height - text_height) / 2,
        ),
        WATERMARK_TEXT,
        font=font,
        fill=(
            WATERMARK_GREY,
            WATERMARK_GREY,
            WATERMARK_GREY,
            WATERMARK_OPACITY,
        ),
    )

    # Rotate around the center.
    watermark = watermark.rotate(
        ROTATION_ANGLE,
        resample=Image.Resampling.BICUBIC,
        expand=False,
    )

    # Composite watermark onto image
    result = Image.alpha_composite(
        image,
        watermark
    )

    return result


# =========================
# Main processing
# =========================

def process_images():
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    input_dir = Path(input('Enter image directory : '))
    if not input_dir.exists():
        print(f"Input directory does not exist: {input_dir}")
        return

    image_files = [
        path
        for path in input_dir.iterdir()
        if path.is_file()
        and path.suffix.lower() in SUPPORTED_FORMATS
    ]

    if not image_files:
        print("No supported images found.")
        return

    print(f"Found {len(image_files)} image(s).")

    for input_path in image_files:
        output_path = OUTPUT_DIR / input_path.name

        try:
            with Image.open(input_path) as image:
                result = add_watermark(image)

                # JPEG doesn't support RGBA
                if output_path.suffix.lower() in {".jpg", ".jpeg"}:
                    result = result.convert("RGB")

                result.save(output_path)

            print(f"Processed: {input_path.name}")

        except Exception as e:
            print(f"Failed: {input_path.name}")
            print(f"  Error: {e}")

    print()
    print(f"Done. Output saved to: {OUTPUT_DIR}")


if __name__ == "__main__":
    process_images()
