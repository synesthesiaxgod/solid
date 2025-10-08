// Modal functionality
document.addEventListener('DOMContentLoaded', function() {
    // Get modal elements
    const licensesModal = document.getElementById('licenses-modal');
    const partnersModal = document.getElementById('partners-modal');
    
    // Get button elements that open modals
    const openLicensesBtn = document.getElementById('open-licenses-modal');
    const openPartnersBtn = document.getElementById('open-partners-modal');
    
    // Get all close buttons
    const closeButtons = document.querySelectorAll('.close-modal');
    
    // Function to open a modal
    function openModal(modal) {
        if (modal) {
            modal.style.display = 'block';
            // Prevent body scroll when modal is open
            document.body.style.overflow = 'hidden';
        }
    }
    
    // Function to close a modal
    function closeModal(modal) {
        if (modal) {
            modal.style.display = 'none';
            // Restore body scroll when modal is closed
            document.body.style.overflow = 'auto';
        }
    }
    
    // Add click event listeners to open buttons
    if (openLicensesBtn) {
        openLicensesBtn.addEventListener('click', function(e) {
            e.preventDefault();
            openModal(licensesModal);
        });
    }
    
    if (openPartnersBtn) {
        openPartnersBtn.addEventListener('click', function(e) {
            e.preventDefault();
            openModal(partnersModal);
        });
    }
    
    // Add click event listeners to close buttons
    closeButtons.forEach(function(button) {
        button.addEventListener('click', function() {
            const modalId = this.getAttribute('data-modal');
            const modal = document.getElementById(modalId);
            closeModal(modal);
        });
    });
    
    // Close modal when clicking outside of modal content
    window.addEventListener('click', function(event) {
        if (event.target.classList.contains('modal')) {
            closeModal(event.target);
        }
    });
    
    // Close modal when pressing Escape key
    document.addEventListener('keydown', function(event) {
        if (event.key === 'Escape') {
            if (licensesModal && licensesModal.style.display === 'block') {
                closeModal(licensesModal);
            }
            if (partnersModal && partnersModal.style.display === 'block') {
                closeModal(partnersModal);
            }
        }
    });
});
